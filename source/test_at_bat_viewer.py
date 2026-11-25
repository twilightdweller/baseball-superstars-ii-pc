"""Exercise keyboard and timer delivery in a hidden instance of the newly built viewer."""
import ctypes as C
from ctypes import wintypes as W
import subprocess
import sys
import time

ui = C.WinDLL('user32', use_last_error=True)
enum_callback = C.WINFUNCTYPE(W.BOOL, W.HWND, W.LPARAM)
ui.EnumWindows.argtypes = [enum_callback, W.LPARAM]
ui.GetWindowThreadProcessId.argtypes = [W.HWND, C.POINTER(W.DWORD)]
ui.GetClassNameW.argtypes = [W.HWND, W.LPWSTR, C.c_int]
ui.GetWindowTextW.argtypes = [W.HWND, W.LPWSTR, C.c_int]
ui.PostMessageW.argtypes = [W.HWND, W.UINT, W.WPARAM, W.LPARAM]

def wait_for(check, description):
    deadline = time.monotonic() + 10
    while time.monotonic() < deadline:
        value = check()
        if value:
            return value
        if viewer.poll() is not None:
            raise RuntimeError(f'viewer exited with {viewer.returncode} while waiting for {description}')
        time.sleep(0.025)
    raise TimeoutError(description)

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

def pitch(number, result, score, terminal=False):
    key(0x20)
    expected = f'BS2 At-Bat | Pitch {number} | {result} | {score} | ' + ('Complete' if terminal else 'Ready')
    wait_for(lambda: title() == expected, expected)

startup = subprocess.STARTUPINFO()
startup.dwFlags |= subprocess.STARTF_USESHOWWINDOW
startup.wShowWindow = 0
viewer = subprocess.Popen([sys.argv[1]], startupinfo=startup)
try:
    hwnd = wait_for(window, 'viewer window')
    wait_for(lambda: title() == 'BS2 Pitch Motion', 'default curve viewer')
    key(ord('T'))
    wait_for(lambda: 'Pitch 0' in title(), 'fresh plate appearance')
    pitch(1, 'Called strike', 'Balls 0, Strikes 1, Outs 0')
    pitch(2, 'Called strike', 'Balls 0, Strikes 2, Outs 0')
    pitch(3, 'Called strikeout', 'Balls 0, Strikes 2, Outs 1', True)
    key(0x20)
    wait_for(lambda: 'Pitch 0' in title(), 'new appearance after strikeout')
    for _ in range(6):
        key(0x27)
    for i in range(1, 5):
        pitch(i, 'Ball' if i < 4 else 'Walk', f'Balls {i}, Strikes 0, Outs 0', i == 4)
    key(ord('T'))
    wait_for(lambda: title() == 'BS2 Pitch Motion', 'return to curve viewer')
    key(0x1b)
    assert viewer.wait(timeout=5) == 0
finally:
    if viewer.poll() is None:
        viewer.kill()
        viewer.wait()
print('PASS: Windows viewer accepted keyboard input, delivered three called strikes and a four-ball walk, reset, returned to curve view and exited.')
