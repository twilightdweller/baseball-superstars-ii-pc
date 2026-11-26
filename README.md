# Baseball Superstars II for Windows

This project is recovering the Android edition of *Baseball Superstars II* for native 64-bit Windows. The immediate goal is to play a complete baseball game as the batter, from the first pitch to the final score. The longer-term goal includes the original game modes and progression, with offline play and an optional premium-currency grant.

**Playable now.** Bat as Ara or Medica against Celine. You can take pitches, swing, walk, strike out, and stay at the plate after a foul. Four empty-base fly-ball variants now go through a confirmed catch. The defensive minimap shows the fielders moving, the out goes on the board, and Space brings up the next practice batter with a fresh count. A third out ends the half. Other fair contact still stops after the ball's flight.

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
| Space or left click | Deliver a pitch, continue after a foul or fly out, or restart practice after an unresolved play | Replay the selected pitch |
| X | Swing once during delivery. Let the ball pass to take the pitch. | |
| Left / Right | Move the practice pitch target horizontally between deliveries | Select one of 369 pitch curves |
| Up / Down | | Switch batter and camera |
| T | Open the pitch browser | Bat with the selected curve and camera |
| Esc | Exit | Exit |

For a quick check, leave the target centered and take three pitches for a called strikeout. Press Space to start again, press Right six times, and take four pitches for a walk. To hit, press X as the pitch reaches the plate. The executable at `build\BS2-Pitch-Motion.exe` opens the pitch browser by default. The launcher passes `--at-bat`.

To reproduce the third baseman's catch, launch `.\build\BS2-Pitch-Motion.exe --at-bat --seed 25`. Leave the target centered, press Space for the first pitch, then immediately press X. After the call, press Space to bat as Medica with one out. The seed fixes the random rolls. Swing timing still matters.

## Milestones

**Estimated completion at checkpoint 16: about 18% of the full port and 24% of the batter-game milestone.** These are engineering estimates of implementation and integration effort. The full-port estimate weights all rows below. The batter-game estimate weights the four rows from pitching through match flow, which account for 45% of the full scope. Test case counts measure coverage of individual routines. An entire nine-inning game has yet to pass an end-to-end test.

| Milestone | Share of full port | Estimated complete | What works and what is next |
| --- | ---: | ---: | --- |
| Windows build and original-code verification | 5% | 90% | MSVC builds a standalone executable. Tests run against the APK's ARM library and drive the Windows UI. Clean-machine verification remains. |
| Graphics, startup and menus | 10% | 30% | Sprite decoding, title-state transitions, a menu preview and two batting views work. The menu still needs to launch a match. |
| Pitching and pitch judgment | 8% | 65% | The port reproduces curve geometry, release positions, camera projection, strike-zone checks and ordinary calls. Pitcher AI, delivery animation and live speed modifiers remain. |
| Batting and contact | 6% | 50% | Two batters can take or swing with recovered timing, matchup abilities, original frames and batted-ball paths. Other roster matchups, bunts and special swings remain. |
| Fielding and baserunning | 16% | 9% | The original defense resolves four recorded empty-base fly balls. Windows shows the original minimap and applies the catch and out timing. Live positioning, throws and runner advancement are open. |
| Rosters, opposing turns and match flow | 15% | 8% | Confirmed fly outs carry the out count and reserved lineup slot into the next practice appearance. Three outs end the half. A full lineup, occupied bases, opposing turns and a final score are open. |
| Original game modes, saves and progression | 28% | 0% | The currency encoding and optional grant have isolated tests. Playable modes, team progression and save/load integration remain. |
| Audio, input, presentation and release testing | 12% | 0% | Practice uses Windows keyboard and mouse controls. Game audio, final presentation and release compatibility testing remain. |

The next acceptance test is a fair ground ball with the defense throwing to first. It requires live native interception and throw timing. The runner and ball must reach the base on their original frames, the native game must apply the original safe or out call, and the next batter must inherit the resulting base occupancy and outs. The full-game milestone also requires opposing turns and the original game-over rules.

## Implementation and verification

The Windows gameplay and renderer are C11 using Win32 and GDI. Python extracts the APK data, builds the native targets, and compares their behavior against individual original ARM routines running in Unicorn. The Windows executable runs independently of Python, Unicorn and Android.

Checkpoint 16 passed all 46 checks on Windows against the supplied APK. The new fielding comparison matched all 1,020 minimap frames and out-count updates across 24 fly-out cases. The Windows input test played a fly out and two strikeouts through the third out. Across 1,232 batted-ball trajectories, native playback matched the original for 53,906 movement ticks, including the final resting positions. The fielding test also checked all 313 untouched fouls. The Windows input test exercised both batting stances and continued play after fouls at zero and two strikes.

The batting build uses a fixed, empty-bases matchup and a 20 ms practice display step. For this stadium, the build records the original trajectory generator's output for each supported batting-pattern variant, including any fence rebounds for its recorded random state. Windows plays back those positions. The defense extractor runs the nine original fielder AIs on the first three shuffled variants of each normal fly-ball group. Four of the nine variants produced an ordinary fly out with both batters and all three starting out counts. The executable embeds those 24 cases and draws the recorded minimap frames. The two supported batters alternate in practice. A full match still needs live native fielding, persistent baserunners and opposing turns.

| Location | Contents |
| --- | --- |
| `source/src/` | Native gameplay, projection, graphics and Windows entry points |
| `source/extract_*.py` | Decoders and build-time extraction from the supplied APK |
| `source/test_*.py` | Original-versus-native comparisons and Windows UI checks |
| `verify_windows.py` | Build and verification entry point; detailed results go into `build/` |
| `source/CHECKPOINT-*.md` | Recovery notes, original routine addresses and test boundaries |

The most recent recovery notes cover [fielding and the next batter](source/CHECKPOINT-16.md), [ball flight and foul judgment](source/CHECKPOINT-15.md), [swing timing and contact selection](source/CHECKPOINT-14.md), [batter artwork and handedness](source/CHECKPOINT-13.md), and [taken-pitch plate appearances](source/CHECKPOINT-12.md).
