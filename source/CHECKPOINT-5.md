# Checkpoint 5: interactive menu preview

Run BS2-Menu-Preview.exe. The title advances to the menu automatically after about three seconds; Space or a click skips the title.

Controls:
- Left/Right: change category or submenu item.
- Down: enter the submenu; further Up/Down moves through its two-column list.
- Up from the first submenu row: return to categories.
- Space: confirm the focused selection using the same press/release handler as a click. Holding Space does not repeatedly confirm.
- Left mouse: press and release on the same button to select it. Releasing outside cancels.
- Escape: return to categories, then close the preview.
- Resize freely. Black borders are excluded from touch coordinates.

## Scope
This is an interactive menu reconstruction using II's actual title image and six recovered menu icons. The layout and input model are new PC code, not a completed port of the original carousel/animation system. The Shop category is represented as Cheats in line with the requested direction, but cheat actions are not connected to game data yet. All leaf selections explicitly report that the destination is unavailable. Gameplay, persistence, audio and the original menu animations are not implemented.

The current click adapter supplies virtual 480x320 press/release coordinates to this menu. It is the basis for future touch controls; it does not establish compatibility with touch elements that have not been ported.

## Validation
Native unit tests pass for category/item wrapping, focus movement, all menu confirmations, keyboard/click handler equivalence, drag-off cancellation, bounds checks, and mouse coordinate conversion at multiple window sizes and aspect ratios. Windows x86-64 cross-build passes with -Wall -Wextra -Werror. GUI behavior requires testing on Windows because no Windows execution environment is available here.

Original title-state and state-machine components are retained. New menu behavior is intentionally not described as differential-equivalent to the original game. An attempt to execute original InitMenuList in the investigation harness did not establish a valid result; it was not used as evidence for this implementation.

Build:
python -m ziglang cc -target x86_64-windows-gnu -O2 -Wall -Wextra -Werror src/menu_app.c src/menu.c src/title_flow.c src/state.c -o BS2-Menu-Preview.exe -lgdi32 -luser32 -Wl,--subsystem,windows

Input-model tests:
gcc -std=c11 -Wall -Wextra -Werror test_menu.c src/menu.c -o test-menu
./test-menu

The Ghidra project from checkpoint 4 is preserved in that checkpoint's archive; it is omitted here to keep the download small.
