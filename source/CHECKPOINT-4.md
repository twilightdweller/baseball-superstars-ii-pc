# Checkpoint 4: title-to-menu state transition

## Windows test
Open BS2-Startup-Test.exe. It displays II's actual English title artwork. After approximately three seconds, the window caption should report that menu state 7 was reached. Press R to repeat or Escape to close.

This is a startup diagnostic, not a playable game. The image deliberately remains visible at the main-menu boundary because the menu renderer is not implemented. It does not run the full original application initialization or its network-linked title substate. The Windows interface has been cross-compiled but not executed in this Linux environment.

## What changed
- Confirmed the active title path through Android's main.xml and showTitleComponent: res/drawable/title_eng.png, 480 by 320 pixels. PZX title assets are not sufficient to reproduce the active Android title display.
- Reconstructed the automatic title substate path in src/title_flow.c.
- Reconstructed the CBBState constructor, reserve, cancel and check routines in src/state.c.
- Added a native Windows diagnostic linking those components. It starts at the established title state instead of claiming the entire original boot sequence is ported.
- Added Ghidra analysis/export scripts in tools/ghidra. Decompiled files in analysis are research output, not buildable source.

## Validation
- 96 title-handler cases matched original ARM object writes, with resource lookup and clock supplied by test hooks. Covers only title substates 0 and 100; substate 1 remains unsupported.
- 2,000 CBBState cases matched original object writes and defined return values. Includes reserved-state cancellation, state locking, and counter wrap.
- Combined native sequence verifies state 6 through 2999 ms, substate 100 at 3000 ms, and a committed state-7 transition on the following tick, retaining previous state 6.
- Original ARM code is used only as the testing oracle. The Windows diagnostic contains native C, artwork and Windows APIs, without ARM emulation or Android.

## Important analysis details
Ghidra loads this ELF at a base offset of 0x10000. For example, original title event address 0x159af8 appears as 0x169af8 in exports. Do not mix those address spaces.

The initial export incorrectly inferred that __aeabi_idiv did not return, truncating menu drawing output. The new analysis disables discovered non-returning function analysis and clears no-return flags on __aeabi helpers. The revised export includes 224 functions. Main-menu drawing expanded from a prematurely truncated 35-line export to 508 lines. The broad automatic analysis reached its 180-second limit; the selected export completed and the project saved. This is partial analysis, and remaining warnings and function-boundary errors still require assembly/reference validation.

## Build on a machine with Python and ziglang
python -m ziglang cc -target x86_64-windows-gnu -O2 -Wall -Wextra -Werror src/startup_test.c src/title_flow.c src/state.c -o BS2-Startup-Test.exe -lgdi32 -luser32 -Wl,--subsystem,windows

## Run the new tests on Linux
Install pyelftools and unicorn. Extract lib/armeabi/libgameDSO.so from the original II APK.

gcc -std=c11 -Wall -Wextra -Werror -O2 -shared -fPIC src/title_flow.c -o /tmp/bs2-title-flow.so
gcc -std=c11 -Wall -Wextra -Werror -O2 -shared -fPIC src/state.c -o /tmp/bs2-state.so
python test_title_flow.py /path/to/libgameDSO.so
python test_state.py /path/to/libgameDSO.so
python test_startup_sequence.py

## Still outstanding
Full application startup, main-menu rendering/animation, menu input and mode selection, gameplay reconstruction, audio, save integration, purchase removal and optional cheat UI. No whole-game feasibility or completion percentage is claimed.
