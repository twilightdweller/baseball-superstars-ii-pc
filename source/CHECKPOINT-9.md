# Baseball Superstars II: native pitch-motion viewer

Extract the ZIP and run `BS2-Pitch-Motion.exe` on 64-bit Windows.
No APK, Android emulator, or additional game files are needed to run this viewer.

## Controls

- Left / Right: browse the 369 extracted curve records.
- Up / Down: switch between camera presets 1 and 2.
- Space or left click: replay the selected path.
- Escape: close.

A gold marker follows the recovered pitch path. A line shows the complete path.
Playback loops with a short pause at each end. The window can be resized.

## What is original and what is diagnostic

The curve data, pitch-positioning calculation, release-position data, and camera
presets come from the supplied II APK. The native implementations were checked
against the original machine code in earlier checkpoints and in this checkpoint.

The marker, line, labels, fixed target, record browser, pause, and replay loop are
new diagnostic UI. The viewer uses base record frame counts and a 20 ms display
step; complete match timing and speed modifiers have not been recovered. It does
not show original ball appearance/size, sprites, stadium artwork, player motion,
batting, or match gameplay. Records are identified numerically because their
pitch-name mapping has not been verified. This is not the final game interface.

The target is fixed at Q18 world coordinates (0, -10, 0). Up/Down selects the two
perspective presets without changing the target. Preset zero is verified in the
tests but omitted from this small viewer because its original origin lies outside
the 480x320 canvas used here. This is not evidence that preset zero is unused.

## New implementation and verification

`camera.c` builds projection matrices from decoded figure records, including the
original lookup trigonometry, float-to-fixed conversion, matrix composition, and
screen origin/scale. All three presets in both supplied version-7 figure layouts
match original `CCLScreen::SetScreen` outputs exactly (six configurations).
The original soft-float and camera math execute during comparison; only external
memory-copy/fill operations are substituted. The tests use controlled screen
initialization, not a running match.

Camera tests passed with UndefinedBehaviorSanitizer enabled. The Windows viewer
compiled with strict warnings as a native x86-64 executable. The first curve was
also projected through both displayed cameras on the development host to confirm
it falls within the viewer canvas. Windows GUI execution still requires the user
to test the supplied executable; no visual Windows verification is claimed.

## Build

From the source directory, with the Python ziglang package installed:

```sh
python -m ziglang cc -target x86_64-windows-gnu -O2 -Wall -Wextra -Werror src/pitch_viewer.c src/pitch_path.c src/pitch_curve.c src/projection.c src/pitch_scene.c src/camera.c -o BS2-Pitch-Motion.exe -lgdi32 -luser32 -Wl,--subsystem,windows
```

Camera comparison (requires original native library, pyelftools, unicorn, GCC):

```sh
gcc -std=c11 -O1 -g -fsanitize=undefined -fno-sanitize-recover=all -Wall -Wextra -Werror -shared -fPIC src/camera.c src/projection.c -o /tmp/bs2-camera.so
python test_camera.py /tmp/baseball-game.so /tmp/bs2-camera.so
```

The archive includes prior source and research. Earlier checkpoint documents
describe historical states. The next integration work is original scene artwork
and animation, then batting input and contact logic.
