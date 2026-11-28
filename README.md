# Baseball Superstars II for Windows

This project is recovering the Android edition of *Baseball Superstars II* for native 64-bit Windows. The immediate goal is to play a complete baseball game as the batter, from the first pitch to the final score. The longer-term goal includes the original game modes and progression, with offline play and an optional premium-currency grant.

**Playable now.** Bat as Ara or Medica against Celine. You can take pitches, swing, walk, strike out, or stay at the plate after an empty-base foul. Nine empty-base grounders can end in a hit or an out at first. Four fly-ball variants play through the catch. When Ara reaches first and Medica hits the supported grounder to the pitcher, the defense can turn two. With two outs the pitcher throws directly to first to end the half. The next batter inherits the count of outs and the remaining runners. Walks and other unresolved contact still end the connected sequence.

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

To play through a single and a double play, start a fresh process with the command below. With the target centered, press Space and immediately press X. Ara beats the throw. After the call, press Space to bring up Medica, then press Space and immediately press X again. The pitcher fields the ball, the second baseman forces Ara out, and the relay beats Medica to first. Press Space to continue with two outs and empty bases.

```powershell
.\build\BS2-Pitch-Motion.exe --at-bat --seed 1184
```

To see the two-out decision with the same seed, start a fresh process and take two called strikeouts before swinging. The same pair of hits now ends with a direct throw to first. Seed 5 gives an opening single, seed 46 an opening ground out, and seed 25 a fly out to the third baseman.

## Milestones

**Estimated completion at checkpoint 19: about 21% of the full port and 29% of the batter-game milestone.** These are engineering estimates of implementation and integration effort. The full-port estimate weights all rows below. The batter-game estimate weights the four rows from pitching through match flow, which account for 45% of the full scope. Test case counts measure coverage of individual routines. An entire nine-inning game has yet to pass an end-to-end test.

| Milestone | Share of full port | Estimated complete | What works and what is next |
| --- | ---: | ---: | --- |
| Windows build and original-code verification | 5% | 90% | MSVC builds a standalone executable. Tests run against the APK's ARM library and drive the Windows UI. Clean-machine verification remains. |
| Graphics, startup and menus | 10% | 30% | Sprite decoding, title-state transitions, a menu preview and two batting views work. The menu still needs to launch a match. |
| Pitching and pitch judgment | 8% | 65% | The port reproduces curve geometry, release positions, camera projection, strike-zone checks and ordinary calls. Pitcher AI, delivery animation and live speed modifiers remain. |
| Batting and contact | 6% | 50% | Two batters can take or swing with recovered timing, matchup abilities, original frames and batted-ball paths. Other roster matchups, bunts and special swings remain. |
| Fielding and baserunning | 16% | 19% | Native C advances two runners and resolves force outs at second and first on one occupied-base grounder. The build records fielder decisions and throws. Other occupied-base hits and runner controls remain open. |
| Rosters, opposing turns and match flow | 15% | 12% | Singles, strikeouts and the supported double play carry the correct outs and bases into the next appearance or end the half. Full lineups, scoring across innings and opposing turns remain open. |
| Original game modes, saves and progression | 28% | 0% | The currency encoding and optional grant have isolated tests. Playable modes, team progression and save/load integration remain. |
| Audio, input, presentation and release testing | 12% | 0% | Practice uses Windows keyboard and mouse controls. Game audio, final presentation and release compatibility testing remain. |

The next acceptance test is a four-ball walk with a runner on first. The batter should take first, the existing runner should reach second, and the next batter should inherit both runners with the same outs and score. A full batter game also requires runs, opposing turns and the original game-over rules.

## Implementation and verification

The Windows gameplay and renderer are C11 using Win32 and GDI. Python extracts the APK data, builds the native targets, and compares their behavior against individual original ARM routines running in Unicorn. The Windows executable runs independently of Python, Unicorn and Android.

The occupied-base test compares six original plays across all three starting out counts, two earlier single variants, different counts and lineup slots. It checks both runner paths, collisions, possession, base occupancy, outs and minimap draws over 280 defensive frames. The Windows input test plays a single followed by the double play and a pitch to the next batter. It also plays the two-out version through the end of the half.

The earlier comparisons cover 39 ground outs, 15 safe finishes, 24 fly outs, 6,518 original collision calls and 53,906 batted-ball motion updates. In all 15 safe finishes, the original runner and the native runner stayed on first through the following batter's first pitch.

The batting build uses a fixed matchup and a 20 ms display step. For all 1,232 supported stadium trajectories, the build records the original generator's output, including fence rebounds for its recorded random state. Native C advances the ball through those positions. For fielding, the build runs the nine original fielder AIs and the batter-runner, collecting their minimap draws, candidate collision inputs, throw timing and each batter's starting position, destination and speed. On supported grounders, Windows moves the runners each tick and checks whether a fielder receives the ball before the forced runner reaches the bag. The stored ending guards against displaying a minimap for a different result. Pursuit and throw generation still run at extraction time. The practice lineup alternates the two batters.

| Location | Contents |
| --- | --- |
| `source/src/` | Native gameplay, projection, graphics and Windows entry points |
| `source/extract_*.py` | Decoders and build-time extraction from the supplied APK |
| `source/test_*.py` | Original-versus-native comparisons and Windows UI checks |
| `verify_windows.py` | Build and verification entry point; detailed results go into `build/` |
| `source/CHECKPOINT-*.md` | Recovery notes, original routine addresses and test boundaries |

The most recent recovery notes cover [the double play and two-out throw](source/CHECKPOINT-19.md), [safe at first and the next pitch](source/CHECKPOINT-18.md), [ground outs and native collision](source/CHECKPOINT-17.md), [fielding and the next batter](source/CHECKPOINT-16.md), [ball flight and foul judgment](source/CHECKPOINT-15.md), [swing timing and contact selection](source/CHECKPOINT-14.md), [batter artwork and handedness](source/CHECKPOINT-13.md), and [taken-pitch plate appearances](source/CHECKPOINT-12.md).
