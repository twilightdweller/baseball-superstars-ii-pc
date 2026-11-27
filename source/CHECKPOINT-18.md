# Checkpoint 18. Safe at first through the next batter's pitch

Seed 5 selects a grounder the pitcher fields for Ara. On the default pitch, an immediate swing sends Ara to first on defensive frame 30. The throw arrives on frame 36. Defense ends on frame 50. Medica comes up with a fresh count, the same outs and Ara on first. The runner's name is visible during the next delivery and pitch judgment.

## Original behavior

| ARM routine | Comparison |
| --- | --- |
| `CBBGRunnerMgr::GetBase` at `0xc8528` | Query the occupant of first after every defensive update. The native lineup slot becomes occupied on the same frame as the original batter-runner. |
| `CBBGRunnerMgr::RunnerSize` at `0xc8614` | A safe finish leaves one runner. A force out leaves zero. The build also checks that second and third are empty. |
| `CBBGEntryMgr::UpdatePlayer` at `0xcc67c` and `CBBGPlayData::ResetSB` at `0xd7ed4` | Commit the reserved slot and reset balls and strikes on the same ARM instance that completed the play. First base still holds the original runner object. |
| `CBBGGameRun::INIT_HANDLER_GSTATE_PITCH_JUDGE` at `0x169f2c` | Judge the next batter's pitch with the base occupied. Compare the native call and count with the APK and check the occupant again. |

The native runner advances from his starting point and speed. The first baseman's pickup is tested against the original collision inputs before that frame's runner update. When the runner beats the throw, judgment 6 stands and outs do not change. On a force out, judgment changes to 13. The resource stores the original final call so the player cannot be shown a recorded minimap with a contradictory ending. The older GRO3 out-only layout remains readable.

## Coverage

The first three variants of each of the three normal ground-ball groups yield 54 cases across two batters and zero, one and two outs. All 39 ground outs remain covered. The 15 additional safe finishes exercise three variants, 777 more defensive frames and 858 more candidate fielder collisions. The first pitch comparisons cover called strikes and balls, including a lineup wrap and a two-out single. On group 3, order 2, Ara beats the throw by one frame. Medica is out on the same variant.

The next play with an existing runner needs both runners' movement and a new fielder decision. Empty-base defense records are ineligible while first is occupied. Walk advancement, runs, opposing turns and a complete game are still open.
