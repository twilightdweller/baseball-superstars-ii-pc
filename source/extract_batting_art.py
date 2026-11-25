"""Bake two fixed batting views using the supplied APK's packed RGB565 sprites."""
from pathlib import Path
import struct
import sys
import zipfile
import zlib

from PIL import Image, ImageDraw
from extract_title import frames, render


class SpriteSheet:
    def __init__(self, apk, name):
        data = apk.read('assets/' + name + '.pzx')
        self.name = name
        self.images = {}
        self.source = list(frames(data))
        pos = struct.unpack_from('<I', data, 8)[0]
        self.kind, count = struct.unpack_from('<BH', data, pos)
        if self.kind not in (0x11, 0x31):
            raise ValueError(f'{name}: unsupported frame table {self.kind:#x}')
        self.offsets = list(struct.unpack_from(f'<{count}I', data, pos+3))
        pos += 3 + 4*count
        size, compressed = struct.unpack_from('<II', data, pos)
        self.table = zlib.decompress(data[pos+8:pos+8+compressed])
        if len(self.table) != size or self.offsets != sorted(self.offsets):
            raise ValueError(f'{name}: invalid frame offsets or size')
        self.offsets.append(size)

    def image(self, index):
        if index not in self.images:
            _, w, h, palette, payload = self.source[index]
            rgb = Image.frombytes('RGB', (w, h), render(w, h, palette, payload), 'raw', 'BGR;16')
            # A white-palette blit distinguishes skipped pixels from opaque black.
            solid = render(w, h, b'\xff' * len(palette), payload)
            rgb.putalpha(Image.frombytes('L', (w, h), solid[::2]))
            self.images[index] = rgb
        return self.images[index]

    def parts(self, frame):
        pos, end = self.offsets[frame:frame+2]
        count, boxes = self.table[pos:pos+2]
        pos += (3 if self.kind == 0x31 else 2) + 8*boxes
        parts = []
        for _ in range(count):
            index, x, y, options = struct.unpack_from('<HhhB', self.table, pos)
            pos += 7
            attrs = {}
            for _ in range(options):
                tag = self.table[pos]
                pos += 1
                if tag in (3, 5):
                    attrs[tag] = True
                elif tag == 102:
                    attrs[tag] = struct.unpack_from('<I', self.table, pos)[0]
                    pos += 4
                else:
                    raise ValueError(f'{self.name}: unsupported part attribute {tag}')
            parts.append((index, x, y, attrs))
        if pos != end:
            raise ValueError(f'{self.name}: frame {frame} length mismatch')
        return parts

    def draw(self, canvas, frame, origin, mirror=False):
        for index, dx, dy, attrs in self.parts(frame):
            if 102 in attrs:
                # Palette effects are outside this static preview.
                continue
            if 5 in attrs:
                raise ValueError(f'{self.name}: unsupported frame transform 5')
            image = self.image(index)
            if mirror != (3 in attrs):
                image = image.transpose(Image.Transpose.FLIP_LEFT_RIGHT)
            x = -dx-image.width if mirror else dx
            canvas.paste(image, (origin[0]+x, origin[1]+dy), image)


def build_scene(sheets, preset):
    left = preset == 2
    # Fixed lower 480x320 viewport of the original 480x390 batting view.
    scroll_y = 320 - 390
    top, bottom = (1, 120, 255), (0, 228, 255)
    scene = Image.new('RGB', (480, 320), top)
    painter = ImageDraw.Draw(scene)
    # Daytime sky from DrawAttCloud and the Q8 RtDrawColorGradationRect steps.
    steps = [int((b-a)*256/153) for a, b in zip(top, bottom)]
    for row in range(153):
        y = scroll_y + 84 + row
        color = tuple(a + (step*row >> 8) for a, step in zip(top, steps))
        painter.line((0, y, 479, y), fill=color)

    index, dx, dy, _ = sheets['ground'].parts(0)[0]
    ground = sheets['ground'].image(index)
    if left:
        ground = ground.transpose(Image.Transpose.FLIP_LEFT_RIGHT)
    scene.paste(ground, (dx-(12 if left else 2), scroll_y+dy), ground)

    # DrawAttFence draws each first-frame tile twice, then the scoreboard frame.
    axis = 208 if left else 272
    for index, dx, dy, _ in sheets['fence'].parts(0):
        image = sheets['fence'].image(index)
        y = scroll_y-3+dy
        scene.paste(image, (axis+dx, y), image)
        flip = image.transpose(Image.Transpose.FLIP_LEFT_RIGHT)
        scene.paste(flip, (axis-dx-image.width-1, y), flip)
    sheets['fence'].draw(scene, 1, (axis, scroll_y-3))

    # Original frame-zero poses. The two pitcher anchors are the projections of
    # defense position zero. The batter anchors come from the handedness table.
    sheets['pitcher'].draw(scene, 0, (251 if left else 230, 206), mirror=left)
    sheets['batter'].draw(scene, 0, (299 if left else 180, scroll_y+364), mirror=left)
    return scene


def main(apk_path, out):
    out.mkdir(exist_ok=True, parents=True)
    with zipfile.ZipFile(apk_path) as apk:
        sheets = {key: SpriteSheet(apk, name) for key, name in {
            'ground': 'stadium/attack', 'fence': 'stadium/fence',
            'pitcher': 'ace/pitcher_celine', 'batter': 'ace/batter_medica',
        }.items()}
        for preset in (1, 2):
            build_scene(sheets, preset).save(out / f'batting-view-{preset}.bmp')
        ball = SpriteSheet(apk, 'ball')
        index, x, y, attrs = ball.parts(7)[0]
        sprite = ball.image(index)
        tile = Image.new('RGB', (17, 17), (255, 0, 255))
        assert not attrs and 0 <= 8+x <= 17-sprite.width and 0 <= 8+y <= 17-sprite.height
        tile.paste(sprite, (8+x, 8+y), sprite)
        tile.save(out / 'pitch-ball.bmp')


if __name__ == '__main__':
    main(sys.argv[1], Path(sys.argv[2]))
