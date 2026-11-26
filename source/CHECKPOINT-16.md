# Checkpoint 16. A confirmed fly out and the next batter

With empty bases, four supported fly balls now play through the original defensive minimap, an ordinary fly out and the end of defense. The next practice batter inherits the out count. A third out produces the side-retired result. The practice session can then restart.

## Original behavior

| ARM ELF address | Routine | Observable result |
| --- | --- | --- |
| `0xad114` | `CCLDefenseMain::BeginDefense` | Initializes the field, the ball, nine defender AIs and the batter-runner. |
| `0xad5b4` | `CCLDefenseMain::Run` | Advances the ball, players, event queue and judgment once per defense update. |
| `0xa5ab0`, `0xae1dc` | `CatchedProcess`, `JudgeFlyOut` | Identifies the defender who took possession and records the ordinary fly-out judgment. A catch after a bounce can lead to a throw instead. |
| `0xabbd0`, `0xcbdac` | `JudgeProcess`, `NextStateAtDefenseEnd` | Records the out. The tested empty-base cases end in state 14 with fewer than three outs and state 25 with three outs. |
| `0x16ca10`, `0xcccec` | `EndOfDefense`, `RsvNextBatter` | Reserves the next lineup slot, including the wrap from slot nine to one. |
| `0xb0a10` | `CCLDefenseDraw::DrawMiniMap` | Supplies each frame's field lines, player markers, ball indicators and RGB565 colors. Windows draws these primitives with GDI. |

The fixture uses the first standard team's fielders, Celine's pitching row, both practice batters, the level table and the default stadium alignment. It runs the original movement and decision code. The fixture supplies team pointers and omits audio, mission, statistics and presentation consumers. It requires the recorded batting-variant seed and empty bases. Windows plays the verified defensive sequence at the practice display rate, applies the out once, and accepts input for the next appearance.

## Coverage

The build tries the first three shuffled variants of each of the three normal fly-ball groups, both batters, and zero, one or two starting outs. Only cases that produce an observed ordinary fly out, increment outs, leave the score at zero, reserve the next slot and finish defense are included. Four of nine ball variants qualified, giving 24 playable cases. The capture window closes at the first bounce if nobody has caught the ball. The other 30 fixture combinations have no fly-out record. An unsupported fair ball stays unresolved.

The differential test starts with a 2-1 count in lineup slot nine and compares the native state transitions and minimap drawing commands to a fresh execution of the APK. Across the 24 fly outs it compares 1,020 map frames and checks the out count on every update. The Windows input test uses seed 25, enters a real swing, watches the minimap change and checks that Medica can take the next pitch with one out. Two subsequent strikeouts carry the same practice half through three outs.

During recovery, the ARM fixture stopped at `CBBEvt::SendEvent` (PC `0xcf5d8`) when a fielder sent an event to the game. Supplying the game-run event receiver and the flow manager's original virtual table allowed that event to reach the game handler.

## Remaining work

The defensive AI and collisions still run at extraction time for these fixed cases. Runtime pursuit and interception, throws, occupied bases, other lineups and the opponent's half remain open. The next ground-ball test should compare possession, throw release, arrival at first, runner arrival and the final call before advancing the lineup.
