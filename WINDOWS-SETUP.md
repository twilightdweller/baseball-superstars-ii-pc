# Windows setup and verification, 2026-11-17

## Update after dependency installation

The user installed pyelftools 0.33 and Unicorn 2.1.4. All original baseline
checks now pass on Windows with MSVC, including all 11 previously blocked ARM
scripts. The failure details below document the initial setup attempt only.
The runner also builds and tests the pitch-rule additions described in
source/CHECKPOINT-10.md. All checks passed after those additions.

The six new helpers passed 4,576 comparisons with original ARM. There is still
no complete at-bat, and no GUI or sanitizer verification is claimed.

## Current state

Read CHECKPOINT-9.md, CHECKPOINT-4 through CHECKPOINT-8, and source/README.md
(which contains the earlier checkpoint history) before making changes.

The supplied project at C:\Projects\BaseballSuperstarsII remains untouched.
This session had read access there, but its writable workspace was elsewhere.
An attempt to create C:\workspace\BaseballSuperstarsII returned Access denied.
The working Git repository is:

    C:\Users\hazii\Documents\Codex\2026-11-17\new-chat-3\BaseballSuperstarsII

Baseline commit: 60f219b. No remote was configured. APKs and generated binaries
are excluded from Git; the supplied APK and executable remain in the working copy.

## Build and test results

Visual Studio Build Tools 2022 was installed but not on PATH. The installed
x64 MSVC compiler (14.43.34808) rebuilt build/BS2-Pitch-Motion.exe with
/std:c11 /O2 /W4 /WX /MT and Windows GDI/User32. No recovered C changes were
required. This is a source rebuild using MSVC, not a byte-identical reproduction
of the earlier Zig-built executable. GUI display/input were not tested.

All eight native verification DLLs and the menu test executable built successfully.
The existing menu test and native startup-sequence test passed.
APK ZIP CRC validation passed. Regenerated pitch data matched all 369 bundled
records across 22 groups. All six figure fixture files matched exactly.

The 11 ARM-dependent scripts below exited with code 1 before running comparisons,
all with `ModuleNotFoundError: No module named 'elftools'`:

- check_original.py
- test_native.py
- test_state.py
- test_title_flow.py
- test_graphics.py
- test_figure_selection.py
- test_pitch_curve.py
- test_cardinal.py
- test_projection.py
- test_pitch_path.py
- test_camera.py

Unicorn is also absent. Installing ziglang, pyelftools, unicorn, capstone and Pillow
into the isolated bs2-tools environment failed because pip could not resolve its
package host: `[Errno 11001] getaddrinfo failed`. Pip subsequently reported no
matching ziglang distribution; this was a connectivity failure, not evidence
that Zig does not support this machine. No package installation succeeded.
No locally built wheels were cached. WSL is not installed. Python 3.11.9,
Git 2.48.1.windows.1 and system Pillow 10.1.0 are available.

No original-versus-native pass, sanitizer pass, or full at-bat is claimed for
this session. Earlier checkpoint results remain historical evidence only.
Detailed outputs and exit codes are in build/*.log and build/results.json.

## Changes

verify_windows.py discovers Visual Studio, builds the viewer and test DLLs,
extracts the ARM reference library, checks APK-derived fixtures, runs the existing
tests, writes individual logs, and returns failure if any check fails.

native_test_library.py permits Windows DLL paths through BS2_TEST_LIB_DIR while
retaining the previous /tmp/*.so behavior when that variable is absent. Five
Python files use this helper in place of a hardcoded Linux path. Assertions,
reference addresses, test cases, and comparison logic are unchanged.

Every supplied C source, header, research export, fixture, APK, and original
executable was compared with the original folder and is byte-identical.

## Resume

From this repository in a normal PowerShell session with package-network access:

```powershell
python -m venv .venv
.\.venv\Scripts\python.exe -m pip install pyelftools unicorn Pillow
.\.venv\Scripts\python.exe verify_windows.py
```

MSVC replaces Zig/GCC for this Windows build; CMake and Ninja are not required.
Capstone and Ghidra may be needed for subsequent recovery, but not these tests.
The runner defaults to the APK in the repository root; --apk accepts another path.
Do not run Python with -O because the original tests rely on assertions.

Once the full differential baseline passes, resume original at-bat recovery:
trace pitch selection and match timing, original batting input/contact and
strike/ball/foul outcomes, then count/plate-appearance termination. Preserve the
ELF-versus-Ghidra address distinction described in CHECKPOINT-4.md. Existing
research includes CheckBattingBallPosition and GetStrikeZoneFramePos3, but their
decompiler output has unresolved constants/calling conventions and is not a
verified implementation. Do not infer these behaviors from the diagnostic viewer.

## SHA-256

Supplied APK:
8c5072f3d249752846c176d95e6dea400a0e65a6d9fa511b6dcf9e3ed545a2b4

Extracted lib/armeabi/libgameDSO.so:
c1f25937bc6edd9efb537d9c3a7cca0362f9399b9a3ed331462c721d15b98a33

MSVC-built viewer:
700c68bbcb2c74d1c765f7c0a53c87301a96f936adc7ae8c3109033c90c9e900
