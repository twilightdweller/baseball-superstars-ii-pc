# Checkpoint 14. Playable normal swings

Open `Play-At-Bat.cmd` after running `python verify_windows.py`. Space delivers the selected pitch. X reserves one swing during delivery. Letting the pitch pass uses the existing called-pitch path. Walks and strikeouts reach the original count and next-batter decision. On contact the Windows build displays the selected batting pattern and pauses before ball flight.

## Original behavior

All addresses below are ELF virtual addresses in the supplied armeabi library.

| Original routine | Native behavior |
| --- | --- |
| `RsvBatting` at 0x12d634 and `DoEvent` at 0x172fd0 | Accept a normal swing during the pitch and retain the tick of the input. The Android normal swing is event 0x6a5. Windows binds it to X. |
| `Swing`, `IsBattable`, `Run`, `GetMotion` at 0xceee0, 0xcedf4, 0xcee0c, 0xce9dc | Latch a swing once. Check contact on the following tick. Ara uses frames 12 through 21, Medica frames 14 through 22. |
| `GetBattingTiming` at 0x163e60 and `GetPitchBallOffsetX/Y` at 0x16f1b8 and 0x16f16c | Score the input at the judge frame, one tick away, or outside that window. Project the pitch target against the figure's batting center and clamp each offset to 40 pixels in either direction. |
| `BattingProcess` at 0xca504 and `bb_rand` at 0xd4f6c | Evaluate timing and location, roll for contact, then select the base pattern using the original integer thresholds and random draw order. |
| `DoEvent` at 0x173144 through 0x173230 | Select the directional variant from handedness and the difference between the judge tick and swing tick plus one. The neutral variant uses the base pattern. |
| `INIT_HANDLER_GSTATE_PITCH_JUDGE` at 0x169f2c | On a miss, supply the swung flag to the same judge, count, reservation and next-state logic already used for a take. |

The matchup uses Ara or Medica against Celine with the base abilities from their APK ace roster rows, normal human batting, empty bases, and no equipment, passive skills, or special bonuses. The isolated ARM test supplies those inputs to the roster and skill queries. It loads the APK level data and executes the original batting and random routines. The C coefficients are specific to those inputs. The practice session seeds the generator from the Windows clock. Window tests use a fixed seed.

The base IDs 0, 3, 9, 15, 18, and 21 denote fly out, ground out, foul, single, double, and home run patterns. The adjacent two IDs are their left and right variants. These names come from `CCLBattingPatternMgr::Pattern2String` at 0x953b0. The original game next looks up a trajectory variation, configures the ball and defense, and advances the play. The Windows build stops before that handoff and leaves the score and count as they stood on contact.

## Verification

- `test_swing.py` compares 3,308 native swings against the original contact flag, selected pattern, and final RNG state. Cases cover exact contact thresholds, all 18 normal contact patterns, both batters, and different counts. It also checks the two swing sequences over 64 ticks.
- `test_taken_pitch.py` compares 150 batting offsets across the two field figures and three cameras. It adds 24 swinging strikeouts inside and outside the zone to the existing 840 complete taken-pitch appearances.
- `test_at_bat_viewer.py` drives the executable with keyboard messages. It checks a walk, called and swinging strikeouts, contact and follow-through for each batter, and an appearance that reaches contact with one ball and one strike.

## Verification failures corrected

The first incremental rebuild hit MSVC LNK1114 (Windows error 5) while replacing `bs2-pitch-path.lib` and `bs2-taken-pitch.lib` after adding exports. The affected DLL tests then reported WinError 193. The verifier now removes the target's generated import library and export file before linking.

The direction comparison initially stopped with Unicorn's `UC_ERR_READ_PROT` because the isolated entry into `DoEvent` needed the pitch singleton slot in R2. The test now provides the register value loaded by the preceding original code. The mixed-count window test also timed out when its synchronous pitch input overtook queued aim inputs. It now sends those aim keys synchronously before delivery.
