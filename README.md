# Baseball Superstars II for Windows

This project is recovering the Android edition of *Baseball Superstars II* for native 64-bit Windows. The immediate goal is to play a complete baseball game as the batter, from the first pitch to the final score. The longer-term goal includes the original game modes and progression, with offline play and an optional premium-currency grant.

**Playable now.** Bat as Ara or Medica against Celine. You can take pitches, swing, walk, strike out, and stay at the plate after an empty-base foul. On nine verified empty-base grounders, the defense fields the ball and throws to first. A runner who beats the throw stays on first through the next batter's pitches. A throw that beats the runner adds one out. Four fly-ball variants also play through the catch. Three outs end the practice half. Walks and contact with a runner already on first still end the connected sequence.

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
| Space or left click | Deliver a pitch, continue after a foul, an out, or reaching first, or restart after a walk or unresolved contact | Replay the selected pitch |
| X | Swing once during delivery. Let the ball pass to take the pitch. | |
| Left / Right | Move the practice pitch target horizontally between deliveries | Select one of 369 pitch curves |
| Up / Down | | Switch batter and camera |
| T | Open the pitch browser | Bat with the selected curve and camera |
| Esc | Exit | Exit |

From the centered target, take three pitches for a called strikeout. Space brings up the next batter. For a walk, move the target right six times and take four pitches. The executable opens the pitch browser by default. The launcher opens batting practice.

To try a ground-ball single, run the command below. With the target centered, press Space and immediately press X. Ara reaches first on defensive frame 30 and the throw arrives on frame 36. Press Space after the play to bring up Medica, then Space again to pitch. The count resets and the scoreboard keeps Ara on first. Use seed 46 for an out at first or seed 25 for the third baseman's fly-ball catch. Start a fresh process for each example.

```powershell
.\build\BS2-Pitch-Motion.exe --at-bat --seed 5
```

## Milestones

**Estimated completion at checkpoint 18: about 20% of the full port and 28% of the batter-game milestone.** These are engineering estimates of implementation and integration effort. The full-port estimate weights all rows below. The batter-game estimate weights the four rows from pitching through match flow, which account for 45% of the full scope. Test case counts measure coverage of individual routines. An entire nine-inning game has yet to pass an end-to-end test.

| Milestone | Share of full port | Estimated complete | What works and what is next |
| --- | ---: | ---: | --- |
| Windows build and original-code verification | 5% | 90% | MSVC builds a standalone executable. Tests run against the APK's ARM library and drive the Windows UI. Clean-machine verification remains. |
| Graphics, startup and menus | 10% | 30% | Sprite decoding, title-state transitions, a menu preview and two batting views work. The menu still needs to launch a match. |
| Pitching and pitch judgment | 8% | 65% | The port reproduces curve geometry, release positions, camera projection, strike-zone checks and ordinary calls. Pitcher AI, delivery animation and live speed modifiers remain. |
| Batting and contact | 6% | 50% | Two batters can take or swing with recovered timing, matchup abilities, original frames and batted-ball paths. Other roster matchups, bunts and special swings remain. |
| Fielding and baserunning | 16% | 17% | Native C resolves the race to first and tracks the runner who reached safely. The build records fielder decisions and throws. Force plays at second and advancement on occupied-base hits remain open. |
| Rosters, opposing turns and match flow | 15% | 11% | Outs, the batting order and a runner on first carry into the next appearance. Three outs end the half. A full lineup, scoring across innings and opposing turns remain open. |
| Original game modes, saves and progression | 28% | 0% | The currency encoding and optional grant have isolated tests. Playable modes, team progression and save/load integration remain. |
| Audio, input, presentation and release testing | 12% | 0% | Practice uses Windows keyboard and mouse controls. Game audio, final presentation and release compatibility testing remain. |

The next acceptance test starts with a runner on first. On a second grounder, Windows must move both runners, reproduce the original fielder's choice of base and record who is safe or out. The next batter must inherit the resulting bases and outs. The full-game milestone also requires opposing turns and the original game-over rules.

## Implementation and verification

The Windows gameplay and renderer are C11 using Win32 and GDI. Python extracts the APK data, builds the native targets, and compares their behavior against individual original ARM routines running in Unicorn. The Windows executable runs independently of Python, Unicorn and Android.

The ground-play comparison covers 39 outs and 15 safe finishes across both batters and all three starting out counts. It checks 2,389 defensive frames, including first-base occupancy on every tick. For every safe finish, the APK switches batters and judges the following pitch while the original runner manager stays active. Windows also plays this sequence through keyboard input. The suite retains the 24 fly-out cases, 6,518 original collision queries and 53,906 batted-ball motion updates.

The batting build uses a fixed matchup and a 20 ms display step. For all 1,232 supported stadium trajectories, the build records the original generator's output, including fence rebounds for its recorded random state. Native C advances the ball through those positions. For fielding, the build runs the nine original fielder AIs and the batter-runner, collecting their minimap draws, candidate collision inputs, throw timing and each batter's starting position, destination and speed. On supported grounders, Windows moves the runner each tick, evaluates both ball contacts and resolves the race to first. The stored ending guards against displaying a minimap for a different result. Pursuit and throw generation still run at extraction time. The practice lineup alternates the two batters.

| Location | Contents |
| --- | --- |
| `source/src/` | Native gameplay, projection, graphics and Windows entry points |
| `source/extract_*.py` | Decoders and build-time extraction from the supplied APK |
| `source/test_*.py` | Original-versus-native comparisons and Windows UI checks |
| `verify_windows.py` | Build and verification entry point; detailed results go into `build/` |
| `source/CHECKPOINT-*.md` | Recovery notes, original routine addresses and test boundaries |

The most recent recovery notes cover [safe at first and the next pitch](source/CHECKPOINT-18.md), [ground outs and native collision](source/CHECKPOINT-17.md), [fielding and the next batter](source/CHECKPOINT-16.md), [ball flight and foul judgment](source/CHECKPOINT-15.md), [swing timing and contact selection](source/CHECKPOINT-14.md), [batter artwork and handedness](source/CHECKPOINT-13.md), and [taken-pitch plate appearances](source/CHECKPOINT-12.md).
