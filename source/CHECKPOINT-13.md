# Checkpoint 13. Batting artwork in the Windows viewer

The Windows build reads the supplied APK and embeds two 480 by 320 batting views and a ball bitmap in the executable. These resources are generated under `build`. The recovered C routines still calculate the release, projected path, strike zone, and taken-pitch outcomes. The curve browser now aims at the endpoint stored in each record so the preview travels toward the plate. Only the curve browser draws the path line.

| APK asset under `assets` | Use in the viewer |
| --- | --- |
| `stadium/attack.pzx` | Grass, mound, foul lines, plate, and batter's boxes |
| `stadium/fence.pzx` | Outfield stands, scoreboard, and skyline |
| `ace/pitcher_celine.pzx` | Celine's assembled frame 0 at the mound |
| `ace/batter_ara.pzx` | Ara's assembled frame 0 in the right-handed box |
| `ace/batter_medica.pzx` | Medica's assembled frame 0 in the left-handed box |
| `ball.pzx` | Frame 7 at the projected ball position |

The extractor handles type 8 shared and per-image RGB565 palettes. A second blit with a white palette identifies pixels skipped by the compressed stream, including the distinction between transparent and opaque black. The player frames use their stored component order and offsets. The fixed viewport shows the lower 320 rows of the 390-row batting layout. The two views follow the ground and fence placement in `DrawAttStadium` (ELF 0x132acc) and `DrawAttFence` (0x130f50). The pitcher anchors use the projected defense position. Batter placement uses the handed batting positions.

## Verification

Run `python verify_windows.py` from the checkout. The graphics test compares the recovered C blitter with the original ARM routine at ELF 0x1aaa78 for every component image in the six gameplay sheets and the two existing title sheets. There are 341 byte-for-byte RGB565 comparisons.

The Windows test captures the running viewer in both camera views and the taken-pitch mode. It compares the field and player regions with the extracted artwork, checks for ball movement during a delivery, and plays a called strikeout and a four-ball walk. The captured right- and left-handed views are saved as `build/at-bat-preview.png` and `build/at-bat-preview-left.png`. The reference for these scene comparisons is the extracted composition. Pixel parity with a complete Android gameplay frame has yet to be measured.

## Batter handedness correction

The first build displayed Medica in both boxes and mirrored her in the left-handed box. The corrected viewer uses Ara in the right-handed box and Medica in the left-handed box. Each uses her authored frame 0. The original ace drawing path in `CBBGBatterRes::Draw` (ELF 0x12f7cc) queues the frame with draw operation zero.

`test_batter_stance.py` runs the original `CBBGBatterRes::LoadRes` and `CBBGPlayerData::IsLeft` for ace IDs 1 and 0. It reads the selected filenames at the resource-load call and takes the batter anchors from the original table at ELF 0x1cf9d4. It compares the visible opaque pixels of each original pose with the corresponding Windows build bitmap. Ara’s component images are also covered by the original ARM blitter test.

## Scope

The preview uses daylight, fixed player poses, a single ball size, and the base stadium palette. Player animation, windup and swing timing, original ball size transitions, palette effects, and live stadium changes remain open. The pitch controls and labels belong to the Windows viewer.
