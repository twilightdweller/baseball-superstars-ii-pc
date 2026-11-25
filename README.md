# Baseball Superstars II native Windows port

You can take a pitch or swing with Ara or Medica. The native C code uses the original timing, pitch location, player abilities, and random rolls. Walks and strikeouts complete the appearance. On contact, play pauses at the batted-ball pattern selected by the game.

## Run on Windows

From the Git checkout, run the following in PowerShell. The verifier requires Visual Studio C++ Build Tools with the Windows SDK, Python, pyelftools, Unicorn, Pillow, and the supplied APK. See [WINDOWS-SETUP.md](WINDOWS-SETUP.md) for setup details.

```powershell
python verify_windows.py
.\build\BS2-Pitch-Motion.exe --at-bat
```

After building, double-click `Play-At-Bat.cmd` to start at the plate. Press **Space** to deliver and **X** as the ball reaches the batter. The executable includes the stadium, pitcher, batter, and ball from the supplied APK and runs on its own. Launch it without arguments to browse all 369 pitch curves. The older executable bundled at the top of the checkpoint 9 archive shows a line and marker.

| Control | Plate appearance | Pitch viewer |
| --- | --- | --- |
| Left / Right | Adjust horizontal aim between pitches | Select curve |
| Space / click | Deliver a pitch, or start fresh after the result | Replay |
| X | Swing once during delivery. Take the pitch by letting it pass. | |
| Up / Down | | Switch camera |
| T | Return to the pitch viewer | Start an appearance with the selected curve and camera |
| Esc | Exit | Exit |

Leave the aim centered and deliver three pitches for a called strikeout. From the center, press **Right** six times and deliver four pitches for a walk. Each appearance starts with empty bases and zero outs. Walks and strikeouts show the next lineup slot the original game reserves. A swinging miss counts as a strike anywhere.

## Recovery status

Normal swings use a fixed, empty-bases matchup against Celine. Both batters use their original swing frames. Each contact selects a fly out, ground out, foul, single, double, or home run pattern, including the original direction variants. Batted-ball flight, fielding, and runner advancement are still needed to score contact. The Windows controls, 20 ms display step, and pitch selection are practice controls. Python builds and tests the port. The executable runs the C implementation.

The [batting recovery notes](source/CHECKPOINT-14.md) describe the original decision routines, matchup inputs, and differential tests.

The [batting graphics notes](source/CHECKPOINT-13.md) describe the asset sources and rendering tests. The [checkpoint 12 report](source/CHECKPOINT-12.md) records the original ARM routines, fixture conditions, comparisons, and test boundaries. Earlier checkpoint documents in `source` describe the earlier builds.
