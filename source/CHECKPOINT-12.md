# Checkpoint 12

The Windows viewer now supports one ordinary plate appearance with the batter taking every pitch. Press T from the curve viewer, or launch `build/BS2-Pitch-Motion.exe --at-bat`. Aim with Left/Right and deliver with Space or a click. The same curve can produce a called strike, ball, called strikeout, or walk.

## Recovered behavior

Addresses below are ELF virtual addresses with the Thumb bit cleared.

| Original routine | ELF address | Behavior exercised |
| --- | --- | --- |
| CCLPitch::SetTotalFrameCount and UpdatePitch | 0xb4238, 0xb43e8 | Allocate three extrapolated samples and select base frame count minus one for judgment. Generate the pitch from the original release and curve record. |
| GetPitchCurveScreenPos and integer TransformPoint | 0xb409c, 0xb38a4 | Project the designated sample, add half a Q18 unit, and convert to integer screen coordinates. |
| CCLFigureMgr::IntersectStrikeZone | 0x96dd0 | Convert the figure's zone center with xToVirtual, project its opposite corners, and include points on all four edges. |
| INIT_HANDLER_GSTATE_PITCH_JUDGE | 0x169f2c | Judge the pitch, update counts and outs, reserve the next batter on a terminal result, and write play byte 0x0c. |
| CBBEvt::SendEvent and CBBGGameRun::DoEvent | 0xcf5e4, 0xcf5cc, 0x172fd0 | Dispatch event 0xbba through the original vtables. The receiver stores the result in play byte 0x0b at 0x173c9c. The flow manager reads this byte. |
| CBBGEntryMgr::RsvNextBatter | 0xcccec | Reserve the next lineup slot with wraparound from slot nine to slot one. |
| EVENT_HANDLER_GSTATE_PITCH_JUDGE | 0x169134 | Reserve the next state at judge tick 15 for an ordinary ball or strike, or 31 for a walk or strikeout. |

The third called strike leaves the strike counter at two and increments outs. Ball four leaves the ball counter at four and sets the defense action to two. An ordinary strike or ball leads to state 16, a walk to state 24, and a called strikeout to state 14 or state 25 for the third out. The new appearance begins from a fresh fixture when the user presses Space after the terminal result.

## Verification

Run `python verify_windows.py` from the repository root. It builds the Windows executable and native comparison DLLs, extracts the reference ELF from the supplied APK, and runs the existing checks and both new tests.

- `test_taken_pitch.py` executes the original frame setup, curve generation, camera, zone test, pitch judge, virtual event dispatch, batter reservation, and timed state handler. It compares both paths before using them, then checks the full play-data buffer, both result bytes, next lineup reservation, defense action, and state reservation around the exact transition tick.
- The suite exercises all 35 legal terminal sequences of taken pitches across the two decoded field layouts, three camera presets, zero or two starting outs, and lineup slots one or nine. This yields 840 appearances and 4,536 pitch comparisons. It also checks the six projected zone rectangles and 486 samples near their boundaries.
- `test_at_bat_viewer.py` starts a private Windows viewer instance, sends keyboard input, and reads the score from the window title. It plays a called strikeout and a four-ball walk, resets the appearance, returns to curve view, and exits.
- The APK SHA-256 is `8c5072f3d249752846c176d95e6dea400a0e65a6d9fa511b6dcf9e3ed545a2b4`. The reference ELF SHA-256 is `c1f25937bc6edd9efb537d9c3a7cca0362f9399b9a3ed331462c721d15b98a33`.

## Boundaries

Fixtures select normal play, empty bases, a batter who takes the pitch, a zero wild-pitch threshold, inactive missions, and disabled auto-simulation. The test executes the original hit-by-pitch and wild-pitch predicates under these conditions. Sound, visual effects, animation resource calls, allocation, memory services, and two statistics calls (AtStrikeOut and ProcJudge) use test doubles. The native viewer omits those statistics. The scoreboard displays the counts as they stand when the judge finishes.

Pitch choice and horizontal offsets are user controls. The native demo uses the recovered base frame counts and a 20 ms display step. It stops at lineup reservation. Running the next batter, advancing runners on a walk, processing an entire inning, and handling swings and contact require further recovery. The automated window test reads state and controls. It does not compare rendered images with the Android game.
