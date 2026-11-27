# Baseball Superstars II for Windows

This project is recovering the Android edition of *Baseball Superstars II* for native 64-bit Windows. The immediate goal is to play a complete baseball game as the batter, from the first pitch to the final score. The longer-term goal includes the original game modes and progression, with offline play and an optional premium-currency grant.

**Playable now.** Bat as Ara or Medica against Celine. You can take pitches, swing, walk, strike out, and stay at the plate after a foul. On supported empty-base grounders, the pitcher fields the ball and throws to first. The defensive minimap shows the play, the first baseman receives the throw, and the next batter comes up with one more out. Four fly-ball variants also play through the catch. Strikeouts carry forward from the opening batter, and the third out ends the practice half. A walk or an unresolved fair ball still ends the connected sequence.

## Build and play

Use Windows x64, Visual Studio 2022 C++ Build Tools with the Windows SDK, and Python 3.11 with `pyelftools`, `unicorn`, and `Pillow`. Place your own matching APK at `baseball-superstars-ii.apk` in the checkout, or pass its path with `--apk`. From the repository root in PowerShell, run:

```powershell
python -m pip install pyelftools unicorn Pillow
python verify_windows.py
.\Play-At-Bat.cmd
```

For an APK in a different folder, use `python verify_windows.py --apk "C:\Games\BaseballSuperstarsII.apk"`. The tested APK has SHA-256 `8c5072f3d249752846c176d95e6dea400a0e65a6d9fa511b6dcf9e3ed545a2b4`. The build extracts artwork and trajectories from that file and embeds them in the Windows executable.

| Control | Batting practice | Pitch browser |
| --- | --- | --- |
| Space or left click | Deliver a pitch, continue after a foul or an out, or restart after a walk or unresolved contact | Replay the selected pitch |
| X | Swing once during delivery. Let the ball pass to take the pitch. | |
| Left / Right | Move the practice pitch target horizontally between deliveries | Select one of 369 pitch curves |
| Up / Down | | Switch batter and camera |
| T | Open the pitch browser | Bat with the selected curve and camera |
| Esc | Exit | Exit |

From the centered target, take three pitches for a called strikeout. Space brings up the next batter. For a walk, move the target right six times and take four pitches. The executable opens the pitch browser by default. The launcher opens batting practice.

To reproduce the throw to first, start a fresh process with the command below. Leave the target centered, press Space, then immediately press X. The pitcher picks up the ball on defensive frame 11, starts the throw on frame 15, and the first baseman receives it on frame 22. Press Space after the call to bat as Medica with one out. Use seed 25 with the same inputs for the third baseman's fly-ball catch.

```powershell
.\build\BS2-Pitch-Motion.exe --at-bat --seed 46
```

## Milestones

**Estimated completion at checkpoint 17: about 19% of the full port and 26% of the batter-game milestone.** These are engineering estimates of implementation and integration effort. The full-port estimate weights all rows below. The batter-game estimate weights the four rows from pitching through match flow, which account for 45% of the full scope. Test case counts measure coverage of individual routines. An entire nine-inning game has yet to pass an end-to-end test.

| Milestone | Share of full port | Estimated complete | What works and what is next |
| --- | ---: | ---: | --- |
| Windows build and original-code verification | 5% | 90% | MSVC builds a standalone executable. Tests run against the APK's ARM library and drive the Windows UI. Clean-machine verification remains. |
| Graphics, startup and menus | 10% | 30% | Sprite decoding, title-state transitions, a menu preview and two batting views work. The menu still needs to launch a match. |
| Pitching and pitch judgment | 8% | 65% | The port reproduces curve geometry, release positions, camera projection, strike-zone checks and ordinary calls. Pitcher AI, delivery animation and live speed modifiers remain. |
| Batting and contact | 6% | 50% | Two batters can take or swing with recovered timing, matchup abilities, original frames and batted-ball paths. Other roster matchups, bunts and special swings remain. |
| Fielding and baserunning | 16% | 14% | Native C moves the batter to first and checks ball pickups, receptions and runner arrival. The build records fielder decisions and throw paths. Safe advancement and occupied-base play remain open. |
| Rosters, opposing turns and match flow | 15% | 9% | Strikeouts, confirmed fly outs and ground outs carry the outs and reserved lineup slot into the next appearance. Three outs end the half. A full lineup, occupied bases, opposing turns and a final score are open. |
| Original game modes, saves and progression | 28% | 0% | The currency encoding and optional grant have isolated tests. Playable modes, team progression and save/load integration remain. |
| Audio, input, presentation and release testing | 12% | 0% | Practice uses Windows keyboard and mouse controls. Game audio, final presentation and release compatibility testing remain. |

The next acceptance test is the other outcome of a throw to first. On normal ground-ball group 3, variant order 2, Ara reaches first before the reception. Medica is out on the same variant. The native game should apply the safe call and keep Ara on first through the next batter's first pitch. The full-game milestone also requires opposing turns and the original game-over rules.

## Implementation and verification

The Windows gameplay and renderer are C11 using Win32 and GDI. Python extracts the APK data, builds the native targets, and compares their behavior against individual original ARM routines running in Unicorn. The Windows executable runs independently of Python, Unicorn and Android.

The checkpoint 17 comparisons cover 39 ground outs across seven ground-ball variants and 24 fly outs across four fly-ball variants. The ground-out comparison checks 1,612 defensive frames and 1,170 candidate fielder collisions in the playable cases. Across the broader fielding sample, native C matched 6,518 calls to the original collision routine, including the exact Q18 coordinates on all 76 contacts. Across the 1,232 batting trajectories it also matched 53,906 position, cursor and stop-state updates. The Windows input test plays the throw to first, brings up Medica, and takes her next pitch with one out.

The batting build uses a fixed matchup and a 20 ms display step. For all 1,232 supported stadium trajectories, the build records the original generator's output, including fence rebounds for its recorded random state. Native C advances the ball through those positions. For fielding, the build runs the nine original fielder AIs and the batter-runner, collecting their minimap draws, candidate collision inputs, throw timing and each batter's starting position, destination and speed. On supported ground outs, Windows moves the runner each tick and evaluates both ball contacts and the race to first before awarding the out. Pursuit and throw generation still run at extraction time. The practice lineup alternates the two batters.

| Location | Contents |
| --- | --- |
| `source/src/` | Native gameplay, projection, graphics and Windows entry points |
| `source/extract_*.py` | Decoders and build-time extraction from the supplied APK |
| `source/test_*.py` | Original-versus-native comparisons and Windows UI checks |
| `verify_windows.py` | Build and verification entry point; detailed results go into `build/` |
| `source/CHECKPOINT-*.md` | Recovery notes, original routine addresses and test boundaries |

The most recent recovery notes cover [ground outs and native collision](source/CHECKPOINT-17.md), [fielding and the next batter](source/CHECKPOINT-16.md), [ball flight and foul judgment](source/CHECKPOINT-15.md), [swing timing and contact selection](source/CHECKPOINT-14.md), [batter artwork and handedness](source/CHECKPOINT-13.md), and [taken-pitch plate appearances](source/CHECKPOINT-12.md).
