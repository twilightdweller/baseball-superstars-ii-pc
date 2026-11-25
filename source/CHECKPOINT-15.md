# Checkpoint 15: ball flight after contact

The Windows batter view now shows the swing follow-through and plays the ball's trajectory after contact. An untouched foul allows the next delivery with the same batter. The strike count stops at two. Fair contact ends at the last sample while fielding and baserunning await integration.

## Recovery

| Original routine | Use |
| --- | --- |
| `CCLGame::SetBattingPattern` (0xaa910) | Generate the batting-view trajectory from the selected variant, decoded 480×320 stadium, fence geometry and the original parabola solver. |
| `CCLBattingPatternMgr::ShufflePatternIndx`, `GetIndex`, `increaseIndex` (0x955b4, 0x95510, 0x9554c) | Establish a reference variant order and advance and wrap its per-group cursor. |
| `CCLBallMovable::BallMoveProcess` (0xb8dd0) | Step the original object so the test can compare the current XYZ position against Windows playback, including ticks after the last sample. |
| `CCLDefenseEnv::SetBattingPattern`, `CCLDefenseMain::BattingBall` (0x163c0c, 0xacf40) | Launch the separate fielding trajectory for the same batting pattern and variant. The batting and fielding views can have different bounce times. |
| `CCLDefenseEnv::JudgeDefenseFoul` (0xae97c) | Determine whether an untouched ball becomes foul. The extraction fixture omits fielder interventions and absorbs event and judge notifications. |
| `CBBGGameRun::EndOfDefense` (0x16cb58), `CBBGPlayData::InccStrikeTo2S` (0xd8220) | Apply the original strike cap following a normal foul. |

## Verification

The Windows verifier completed 44 build, extraction, fixture and test checks. It produced 1,232 trajectories containing 51,442 XYZ positions across all 18 normal-swing pattern groups. The native reader matched the original movable on all 53,906 tested ticks, including two post-flight ticks per trajectory. The defense comparison stepped every field trajectory and matched the result for all 313 untouched fouls. Windows UI tests observed the ball in flight, the follow-through artwork for both batters, and the next pitch after fouls at zero and two strikes.

An initial comparison exposed a random fence rebound. Foul pattern group 9, variant order 51, yielded different trajectory lengths when replayed with a different random state. Each record now retains the launch seed so the test reproduces the original rebound. The build records one original flight per variant and seed. Runtime live rebounds from arbitrary seeds, fielder catches, fair-ball outcomes and runner movement remain open. The port presents the untouched-foul call after the batting-view animation completes.
