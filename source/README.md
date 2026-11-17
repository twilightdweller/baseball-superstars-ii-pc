# Latest: checkpoint 4

See CHECKPOINT-4.md for the new BS2-Startup-Test.exe diagnostic and validation. The asset viewer below is retained as an earlier tool.

# Checkpoint 3: native Windows graphics viewer

Extract this ZIP, open the bs2-native folder, and double-click BS2-Asset-Viewer.exe.
Use Left/Right arrows or Space to browse 30 recovered title-screen images. Escape closes the viewer. Resize the window freely. Transparent areas appear black in this diagnostic viewer.

This is an asset viewer, not the running game. It does not implement title-screen interactions, gameplay, audio, saves, or purchases. Its purpose is to validate an actual native Windows graphics component using the original artwork.

## Validation
- Reconstructed the indexed RGB565 run-length drawing routine in portable C.
- Decoded 17 images from assets/ui/title.pzx and 13 from assets/mainui/main_title.pzx.
- All 30 native C outputs match the original ARM drawing routine byte for byte on zero-filled destination buffers. The reference harness is development-only; it is not part of the viewer.
- Compiled a Windows x86-64 GUI executable with warnings treated as errors.
- Confirmed imports are standard Windows and Universal CRT libraries; no Android/ARM runtime.
- Visually inspected an extracted title image.
- Windows GUI execution is NOT tested in this Linux environment. Please report whether the viewer opens and arrows switch images.

## Build and tests
Install Python packages ziglang, pyelftools, capstone, unicorn, Pillow.
Windows cross-build:
python -m ziglang cc -target x86_64-windows-gnu -O2 -Wall -Wextra -Werror src/viewer.c src/graphics.c -o BS2-Asset-Viewer.exe -lgdi32 -luser32 -Wl,--subsystem,windows

Linux graphics test library:
gcc -std=c11 -Wall -Wextra -Werror -O2 -shared -fPIC src/graphics.c -o /tmp/bs2-graphics.so
python test_graphics.py /path/to/libgameDSO.so /path/to/baseball-superstars-ii.apk

The parser currently supports only the type-8, flags-0 PZX containers and mode-2 images used by these title files. Other asset variants and drawing operations still need reconstruction. The viewer embeds recovered compressed image payloads and palettes in src/assets.h. Its decoder handles skip runs, literal runs, row markers, and termination, with bounds checks.

## Next engineering work
Recover the application state transitions and startup platform calls, decode remaining asset variants and frame/animation layout tables, and integrate the game logic with native rendering/input. This viewer does not prove that all game code can be converted automatically.

---
Prior currency/startup checkpoint follows:

# Baseball Superstars II native-port checkpoint 2

This is an engineering checkpoint, not a playable game or Windows executable.

## Working component
src/currency.c reconstructs the original balance encoding, checksum, set and add behavior. It compiles as native C without Android or ARM execution. A proposed optional cheat grant leaves the balance untouched when disabled and caps grants at 999,999 when enabled. Integration with game saves/UI remains pending.

Validation: compiled with GCC C11, warnings treated as errors. 2,000 deterministic cases compare encoded balances and checksums with the original ARM routines, plus readback and cheat disabled/enabled checks. All passed. Unicorn is used only as the reference oracle during development.

The original GetGPoint routine also handles corrupted balances by calling a game error routine, and resets over-limit decoded balances. The native bs2_get helper currently only decodes; callers must not treat it as a complete replacement for the original validation/error path. No saved-game compatibility is claimed.

## Startup path verified by disassembly
NativeInitWithBufferSize -> platform/display setup -> startClet.
startClet -> GxCreateGlobalHeap -> Gcx_MM_Init with 1 MiB heap.
startClet -> GxCreateFrameT1 -> allocate 132 bytes -> CBBStartUp constructor.
startClet -> GxSendEvent(0xa000, 0, 0) -> handleCletEvent.
NativeRender -> one-time glInit -> threadCallback -> glDrawFrame.
paintClet -> GxPostEvent(0xa600, 0, 0).

The renderer and app startup remain compiled ARM code. No title screen has been rendered. Whole-game translation, imports/relocations, indirect calls, Android interface replacements, saving and server-dependency checks remain unresolved. The binary contains 7,325 defined dynamic function entries, not necessarily that many distinct implementation bodies.

## Reproduce on a Linux development host
Extract lib/armeabi/libgameDSO.so from your original APK.
Install Python pyelftools, capstone and unicorn.
Compile: gcc -std=c11 -Wall -Wextra -Werror -O2 -shared -fPIC src/currency.c -o /tmp/bs2-currency.so
Run: python test_native.py /path/to/libgameDSO.so

The compiled library is a host-side validation component. A Windows compiler and Windows testing are still required for a Windows deliverable.
