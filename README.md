# Baseball Superstars II native Windows port

The Windows viewer runs recovered C gameplay code. Press **T** to start one plate appearance with the batter taking every pitch. The original pitch curve, camera, and strike zone determine the call. The appearance ends in a called strikeout or a walk.

## Run on Windows

From the Git checkout, run the following in PowerShell. The verifier requires Visual Studio C++ Build Tools with the Windows SDK, Python, pyelftools, Unicorn, Pillow, and the supplied APK. See [WINDOWS-SETUP.md](WINDOWS-SETUP.md) for setup details.

```powershell
python verify_windows.py
.\build\BS2-Pitch-Motion.exe --at-bat
```

The resulting executable runs on its own. Launch it without arguments to open the 369-record pitch viewer.

| Control | Taken-pitch appearance | Pitch viewer |
| --- | --- | --- |
| Left / Right | Adjust horizontal aim between pitches | Select curve |
| Space / click | Deliver a pitch, or start fresh after the result | Replay |
| Up / Down | | Switch camera |
| T | Return to the pitch viewer | Start an appearance with the selected curve and camera |
| Esc | Exit | Exit |

Leave the aim centered and deliver three pitches for a called strikeout. From the center, press **Right** six times and deliver four pitches for a walk. Each appearance starts with empty bases and zero outs. The terminal screen shows the next lineup slot the original game reserves.

## Recovery status

The native code covers taken pitches in normal play from the generated curve through the count, terminal result, lineup reservation, and the next state decision. The controls, pitch marker, and 20 ms display step are diagnostic. Swing input, bat contact, live pitch selection, runner advancement, and a continuous match remain open. Python builds and tests the port. The Windows executable runs the C implementation.

The [checkpoint 12 report](source/CHECKPOINT-12.md) records the original ARM routines, fixture conditions, comparisons, and test boundaries. Earlier checkpoint documents in `source` describe the earlier builds.
