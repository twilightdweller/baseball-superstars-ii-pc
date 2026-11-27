"""Check the rendered field, keyboard input and pitch delivery in an off-screen viewer."""
import ctypes as C
from ctypes import wintypes as W
from pathlib import Path
from PIL import Image, ImageChops
from viewer_capture import capture
import subprocess
import sys
import time

ui = C.WinDLL('user32', use_last_error=True)
enum_callback = C.WINFUNCTYPE(W.BOOL, W.HWND, W.LPARAM)
ui.EnumWindows.argtypes = [enum_callback, W.LPARAM]
ui.GetWindowThreadProcessId.argtypes = [W.HWND, C.POINTER(W.DWORD)]
ui.GetClassNameW.argtypes = [W.HWND, W.LPWSTR, C.c_int]
ui.GetWindowTextW.argtypes = [W.HWND, W.LPWSTR, C.c_int]
ui.SendMessageW.argtypes = [W.HWND, W.UINT, W.WPARAM, W.LPARAM]
ui.PostMessageW.argtypes = [W.HWND, W.UINT, W.WPARAM, W.LPARAM]
ui.SetWindowPos.argtypes = [W.HWND, W.HWND, C.c_int, C.c_int, C.c_int, C.c_int, W.UINT]

def wait_for(check, description):
    deadline = time.monotonic() + 10
    while time.monotonic() < deadline:
        value = check()
        if value:
            return value
        if viewer.poll() is not None:
            raise RuntimeError(f'viewer exited with {viewer.returncode} while waiting for {description}')
        time.sleep(0.025)
    last_title = title() if "hwnd" in globals() else "<window unavailable>"
    raise TimeoutError(f"{description}. Last window title: {last_title}")

def window():
    hits = []
    @enum_callback
    def visit(hwnd, lparam):
        pid = W.DWORD()
        ui.GetWindowThreadProcessId(hwnd, C.byref(pid))
        if pid.value == viewer.pid:
            name = C.create_unicode_buffer(128)
            ui.GetClassNameW(hwnd, name, len(name))
            if name.value == 'BS2PitchMotion':
                hits.append(hwnd)
                return False
        return True
    ui.EnumWindows(visit, 0)
    return hits[0] if hits else None

def title():
    buf = C.create_unicode_buffer(200)
    ui.GetWindowTextW(hwnd, buf, len(buf))
    return buf.value

def key(code):
    assert ui.PostMessageW(hwnd, 0x100, code, 0), C.get_last_error()

def check_art(preset, preview=False):
    build = Path(sys.argv[1]).resolve().parent
    with Image.open(build / f'batting-view-{preset}.bmp') as reference:
        rendered = capture(hwnd)
        scenes = [(0, 90, 480, 320), (205, 152, 275, 209),
                  (130, 204, 213, 294) if preset == 1 else (267, 204, 350, 294)]
        for box in scenes:
            crop = rendered.crop(box)
            expected = reference.crop(box)
            assert len(crop.getcolors(crop.width * crop.height)) > 40, (preset, box, 'missing artwork')
            diff = ImageChops.difference(crop, expected).convert('RGB')
            same = sum(n for n, color in diff.getcolors(crop.width*crop.height) if color == (0, 0, 0))
            assert same >= crop.width*crop.height*0.95, (preset, box, same)
        if preview:
            filename = 'at-bat-preview.png' if preset == 1 else 'at-bat-preview-left.png'
            rendered.save(build / filename)

def pitch(number, result, score, terminal=False):
    # On the first delivery, the only moving artwork below the scoreboard is the ball.
    region = (185, 140, 285, 285)
    first_delivery = number == 1 and result == 'Called strike'
    if first_delivery:
        before = capture(hwnd).crop(region)
    key(0x20)
    if first_delivery:
        def ball_moved():
            diff = ImageChops.difference(capture(hwnd).crop(region), before)
            bounds = diff.getbbox()
            return bounds and bounds[3] - bounds[1] > 10
        wait_for(ball_moved, 'ball moving from the pitcher toward the plate')
    expected = f'BS2 At-Bat | Pitch {number} | {result} | {score} | ' + ('Complete' if terminal else 'Ready')
    wait_for(lambda: title() == expected, expected)

def swing_contact(preset, score="Balls 0, Strikes 0, Outs 0"):
    # The first curve's judge tick is 15. Send synchronously so message-queue
    # latency before the delivery does not eat the one-tick timing margin.
    ui.SendMessageW(hwnd, 0x100, 0x20, 0)
    time.sleep(0.305)
    ui.SendMessageW(hwnd, 0x100, ord('X'), 0)
    wait_for(lambda: '| Ball in play |' in title(), 'ball released after contact')
    # Above the plate, between the HUD and the batter's swing artwork.
    field = (0, 89, 480, 180)
    start = capture(hwnd).crop(field)
    wait_for(lambda: ImageChops.difference(start, capture(hwnd).crop(field)).getbbox(),
             'batted ball traveling over the field')
    wait_for(lambda: f'| Contact | {score} | ' in title() and ' pattern' in title(), 'timed swing selected a batting pattern')
    build = Path(sys.argv[1]).resolve().parent
    with Image.open(build / f'swing-{preset}.bmp') as atlas:
        region = (96, 185, 355, 307)
        last = atlas.height - 320
        expected = atlas.crop((region[0], region[1]+last, region[2], region[3]+last))
        # The zone is drawn on top of the frame. Sample the batter's box.
        box = (0, 0, 100, 122) if preset == 1 else (178, 0, 259, 122)
        expected = expected.crop(box).tobytes()
        wait_for(lambda: capture(hwnd).crop(region).crop(box).tobytes() == expected, 'original swing follow-through')
    key(0x20)
    wait_for(lambda: 'Pitch 0 | Ready' in title(), 'fresh count after contact')


ui.SetProcessDPIAware()
startup = subprocess.STARTUPINFO()
startup.dwFlags |= subprocess.STARTF_USESHOWWINDOW
startup.wShowWindow = 0
viewer = subprocess.Popen([sys.argv[1], '--fixed-seed'], startupinfo=startup)
try:
    hwnd = wait_for(window, 'viewer window')
    wait_for(lambda: title() == 'BS2 Pitch Motion', 'default curve viewer')
    # Give DWM an off-screen client surface while keeping the user's focus.
    assert ui.SetWindowPos(hwnd, None, -16300, -16300, 0, 0, 0x55)
    check_art(1)
    with Image.open(Path(sys.argv[1]).resolve().parent / 'batting-view-2.bmp') as field:
        # This strip of the left batter's box changes with handedness and stays clear of the ball.
        strip = (112, 270, 162, 280)
        expected_strip = field.crop(strip).tobytes()
    key(0x26)
    wait_for(lambda: capture(hwnd).crop(strip).tobytes() == expected_strip, 'second batting view')
    check_art(2)
    key(ord('T'))
    wait_for(lambda: 'Pitch 0' in title(), 'left-handed plate appearance')
    check_art(2, preview=True)
    swing_contact(2)
    key(ord('T'))
    wait_for(lambda: title() == 'BS2 Pitch Motion', 'return from left-handed appearance')
    key(0x26)
    key(ord('T'))
    wait_for(lambda: 'Pitch 0' in title(), 'fresh plate appearance')
    check_art(1, preview=True)
    pitch(1, 'Called strike', 'Balls 0, Strikes 1, Outs 0')
    pitch(2, 'Called strike', 'Balls 0, Strikes 2, Outs 0')
    pitch(3, 'Called strikeout', 'Balls 0, Strikes 2, Outs 1', True)
    key(0x20)
    wait_for(lambda: 'Outs 1 | Ready | Slot 2: Medica' in title(), 'next batter after opening strikeout')
    pitch(1, 'Called strike', 'Balls 0, Strikes 1, Outs 1')
    # Return to the original matchup for the four-ball comparison.
    key(ord('T'))
    key(0x26)
    key(ord('T'))
    wait_for(lambda: 'Outs 0 | Ready' in title(), 'restart practice for the walk')
    for _ in range(6):
        key(0x27)
    for i in range(1, 5):
        pitch(i, 'Ball' if i < 4 else 'Walk', f'Balls {i}, Strikes 0, Outs 0', i == 4)
    key(0x20)
    wait_for(lambda: 'Pitch 0 | Ready' in title(), 'fresh count after walk')
    swing_contact(1)
    for _ in range(6):
        key(0x27)
    pitch(1, 'Ball', 'Balls 1, Strikes 0, Outs 0')
    key(0x20)
    key(ord('X'))
    wait_for(lambda: 'Pitch 2 | Swinging strike | Balls 1, Strikes 1, Outs 0 | Ready' in title(), 'miss at 1-0')
    for _ in range(6):
        ui.SendMessageW(hwnd, 0x100, 0x25, 0)
    swing_contact(1, 'Balls 1, Strikes 1, Outs 0')
    for _ in range(6):
        key(0x27)
    for i in range(1, 4):
        key(0x20)
        key(ord('X'))
        key(ord('X'))
        expected = (f'Pitch {i} | Swinging strike | Balls 0, Strikes {i}, Outs 0 | Ready'
                    if i < 3 else 'Pitch 3 | Swinging strikeout | Balls 0, Strikes 2, Outs 1 | Complete')
        wait_for(lambda: expected in title(), expected)
    key(ord('T'))
    wait_for(lambda: title() == 'BS2 Pitch Motion', 'return to curve viewer')
    key(0x1b)
    assert viewer.wait(timeout=5) == 0
    # Exercise the same command-line entry point as Play-At-Bat.cmd.
    viewer = subprocess.Popen([sys.argv[1], '--at-bat'], startupinfo=startup)
    hwnd = wait_for(window, 'direct at-bat window')
    wait_for(lambda: 'Pitch 0 | Ready | Balls 0, Strikes 0, Outs 0' in title(), 'direct at-bat startup')
    key(0x1b)
    assert viewer.wait(timeout=5) == 0
    # Seed 25 selects this fly ball for an immediate swing on the first pitch.
    viewer = subprocess.Popen([sys.argv[1], '--at-bat', '--seed', '25'], startupinfo=startup)
    hwnd = wait_for(window, 'fielding test window')
    assert ui.SetWindowPos(hwnd, None, -16300, -16300, 0, 0, 0x55)
    ui.SendMessageW(hwnd, 0x100, 0x20, 0)
    ui.SendMessageW(hwnd, 0x100, ord('X'), 0)
    wait_for(lambda: '| Fielding |' in title(), 'defensive minimap')
    region = (121, 115, 359, 302)
    first = capture(hwnd).crop(region)
    assert len(first.getcolors(1000) or []) >= 5, 'missing fielders or field lines'
    wait_for(lambda: ImageChops.difference(first, capture(hwnd).crop(region)).getbbox(), 'fielder movement')
    wait_for(lambda: 'Fly out | Balls 0, Strikes 0, Outs 1 | Complete | Third baseman' in title(), 'fly out')
    key(0x20)
    wait_for(lambda: 'Pitch 0 | Ready | Balls 0, Strikes 0, Outs 1 | Ready | Slot 2: Medica' in title(),
             'second batter with one out')
    check_art(2, preview=True)
    pitch(1, 'Called strike', 'Balls 0, Strikes 1, Outs 1')
    pitch(2, 'Called strike', 'Balls 0, Strikes 2, Outs 1')
    pitch(3, 'Called strikeout', 'Balls 0, Strikes 2, Outs 2', True)
    key(0x20)
    wait_for(lambda: 'Outs 2 | Ready | Slot 3: Ara' in title(), 'third batter with two outs')
    pitch(1, 'Called strike', 'Balls 0, Strikes 1, Outs 2')
    pitch(2, 'Called strike', 'Balls 0, Strikes 2, Outs 2')
    key(0x20)
    wait_for(lambda: 'Outs 3 | Complete | Side retired' in title(), 'end of the half')
    key(0x20)
    wait_for(lambda: 'Pitch 0 | Ready | Balls 0, Strikes 0, Outs 0' in title(), 'restart after three outs')
    key(0x1b)
    assert viewer.wait(timeout=5) == 0
    print('PASS: A fly out displayed the moving defensive minimap and carried one out into the next batter\'s pitch.')
    viewer = subprocess.Popen([sys.argv[1], '--at-bat', '--seed', '46'], startupinfo=startup)
    hwnd = wait_for(window, 'ground-ball test window')
    assert ui.SetWindowPos(hwnd, None, -16300, -16300, 0, 0, 0x55)
    ui.SendMessageW(hwnd, 0x100, 0x20, 0)
    ui.SendMessageW(hwnd, 0x100, ord('X'), 0)
    wait_for(lambda: '| Fielding |' in title(), 'ground ball on the defensive minimap')
    wait_for(lambda: 'Ground out | Balls 0, Strikes 0, Outs 1 | Complete | Out at first' in title(),
             'ground out after the throw to first')
    key(0x20)
    wait_for(lambda: 'Outs 1 | Ready | Slot 2: Medica' in title(), 'next batter after ground out')
    pitch(1, 'Called strike', 'Balls 0, Strikes 1, Outs 1')
    key(0x1b)
    assert viewer.wait(timeout=5) == 0
    print('PASS: Seed 46 grounder reached first for the out, then Medica took a pitch with one out.')
    # Seed 22 selects a normal foul on the first timed swing of this matchup.
    viewer = subprocess.Popen([sys.argv[1], '--at-bat', '--seed', '22'], startupinfo=startup)
    hwnd = wait_for(window, 'foul test window')
    assert ui.SetWindowPos(hwnd, None, -16300, -16300, 0, 0, 0x55)
    for initial_strikes in (0, 2):
        for i in range(initial_strikes):
            pitch(i+1, 'Called strike', f'Balls 0, Strikes {i+1}, Outs 0')
        ui.SendMessageW(hwnd, 0x100, 0x20, 0)
        time.sleep(0.305)
        ui.SendMessageW(hwnd, 0x100, ord('X'), 0)
        strikes = min(2, initial_strikes+1)
        expected = f'Pitch {initial_strikes+1} | Foul ball | Balls 0, Strikes {strikes}, Outs 0 | Ready'
        wait_for(lambda: expected in title(), expected)
        if initial_strikes == 0:
            pitch(2, 'Called strike', 'Balls 0, Strikes 2, Outs 0')
            pitch(3, 'Called strikeout', 'Balls 0, Strikes 2, Outs 1', True)
            key(ord('T'))
            key(ord('T'))
            wait_for(lambda: 'Pitch 0 | Ready' in title(), 'reset after first foul test')
        else:
            pitch(4, 'Called strikeout', 'Balls 0, Strikes 2, Outs 1', True)
    key(0x1b)
    assert viewer.wait(timeout=5) == 0
    print('PASS: Untouched fouls at zero and two strikes kept the batter at the plate through the next pitch.')
finally:
    if viewer.poll() is None:
        viewer.kill()
        viewer.wait()
print('PASS: Both batters made timed contact. The viewer preserved a 1-1 count on contact, handled three misses outside the zone, and opened directly in at-bat mode.')
print('PASS: Both batting views and at-bat artwork rendered. Windows viewer accepted keyboard input, delivered three called strikes and a four-ball walk, reset, returned to curve view and exited.')
