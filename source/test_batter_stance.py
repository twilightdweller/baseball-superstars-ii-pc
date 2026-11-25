"""Compare the two baked batter poses with the original ace selection and box table."""
import struct
import sys
import zipfile
from pathlib import Path

from elftools.elf.elffile import ELFFile
from PIL import Image, ImageChops
from unicorn import Uc, UC_ARCH_ARM, UC_MODE_THUMB, UC_HOOK_CODE
from unicorn.arm_const import (UC_ARM_REG_R0, UC_ARM_REG_R1, UC_ARM_REG_R2,
                               UC_ARM_REG_R3, UC_ARM_REG_SP, UC_ARM_REG_PC, UC_ARM_REG_LR)
from extract_batting_art import SpriteSheet


def original_stance(arm, ace):
    resource, player = 0x400000, 0x500000
    arm.mem_write(resource, bytes(256))
    arm.mem_write(resource + 0x2d, b'\xff')  # No previously loaded ace.
    arm.mem_write(player + 0x0b, bytes([0x40 | ace]))
    for reg, value in [(UC_ARM_REG_R0, resource), (UC_ARM_REG_R1, 0), (UC_ARM_REG_R2, player),
                       (UC_ARM_REG_R3, ace), (UC_ARM_REG_SP, 0x900000), (UC_ARM_REG_LR, 0xa00001)]:
        arm.reg_write(reg, value)
    # Run LoadRes, including IsLeft. Stop at the original request for the PZX file.
    arm.emu_start(0x12fc91, 0xd43a4, count=5000)
    assert arm.reg_read(UC_ARM_REG_PC) == 0xd43a4
    filename = bytes(arm.mem_read(arm.reg_read(UC_ARM_REG_R0), 64)).split(b'\0', 1)[0].decode()
    left = arm.mem_read(resource + 0x2c, 1)[0]
    assert left in (0, 1)
    # DrawBatter indexes this coordinate table using the batter's side.
    x, y = struct.unpack('<ii', arm.mem_read(0x1cf9d4 + 8*left, 8))
    return filename, left, (x, y - 70)


def check_pose(apk, filename, anchor, scene):
    sheet = SpriteSheet(apk, filename.removesuffix('.pzx'))
    pose = Image.new('RGBA', scene.size)
    for index, dx, dy, attrs in sheet.parts(0):
        assert attrs.keys() <= {3}, (filename, index, attrs)
        part = sheet.image(index)
        if 3 in attrs:
            part = part.transpose(Image.Transpose.FLIP_LEFT_RIGHT)
        pose.alpha_composite(part, (anchor[0] + dx, anchor[1] + dy))
    mask = pose.getchannel('A')
    assert mask.getbbox()
    difference = ImageChops.difference(scene.convert('RGB'), pose.convert('RGB'))
    for channel in difference.split():
        assert not ImageChops.multiply(channel, mask).getbbox(), (filename, anchor, 'wrong batter pose')


def main(elf_path, apk_path, build):
    arm = Uc(UC_ARCH_ARM, UC_MODE_THUMB)
    arm.mem_map(0, 0x1000000)
    with open(elf_path, 'rb') as stream:
        for segment in ELFFile(stream).iter_segments():
            if segment['p_type'] == 'PT_LOAD':
                arm.mem_write(segment['p_vaddr'], segment.data())

    # Our empty fixture owns no resources for DeleteResAll to release.
    def skip_empty_release(cpu, address, size, data):
        cpu.reg_write(UC_ARM_REG_PC, cpu.reg_read(UC_ARM_REG_LR))
    arm.hook_add(UC_HOOK_CODE, skip_empty_release, begin=0x12fc88, end=0x12fc88)

    with zipfile.ZipFile(apk_path) as apk:
        for ace, preset in [(1, 1), (0, 2)]:
            filename, left, anchor = original_stance(arm, ace)
            assert left == preset - 1
            with Image.open(build / f'batting-view-{preset}.bmp') as scene:
                check_pose(apk, filename, anchor, scene)
            print(f'PASS: camera {preset}, {filename}, {"left" if left else "right"}-handed, anchor {anchor}.')


if __name__ == '__main__':
    main(sys.argv[1], sys.argv[2], Path(sys.argv[3]))
