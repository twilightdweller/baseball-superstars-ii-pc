# Checkpoint 17. The throw to first

Seed 46, an immediate swing on the first pitch, and the centered target produce a pitcher-to-first ground out for Ara. Defensive ticks start at one. The pitcher fields it on tick 11 and begins the throw on tick 15. The first baseman takes possession on tick 22. Defense ends on tick 36. Space brings Medica to the plate with one out. A strikeout by the opening batter now uses the same lineup transition. A third out ends practice for the half.

## What runs in the Windows executable

| Original routine | Native behavior |
| --- | --- |
| `CCLBallMovable::BallMoveProcess` at `0xb8dd0` | Expose the current Q18 position, advance the cursor, stop on the final sample. Catch up missed display ticks in order. |
| `CCLBallMovable::CalcVelocity` at `0xb7fcc` | Compute speed between adjacent trajectory samples using the original fixed-point distance and integer square root. |
| `CCLBallMovable::CollisionDetect` at `0xb8024` | Test the original speed limit, interpolate between adjacent samples, apply the defender's bounds and radius, and return the first contact point. Stopping the ball and disabling collisions are separate flags. |
| `CBBMovable::MoveNext` at `0xcf264` | Advance the batter on level ground from the original start, destination and speed. The original snaps within one stride and otherwise divides the X and Z components by the sum of their absolute differences. |
| `CBBMovable::IsArrive` at `0xcf3e4` and `CCLRunnerAIMain::IsArrive` at `0x98bc4` | Check the runner's three destination coordinates, then compare X and Z to the stadium's base position. |
| Ordinary force out at first | Apply provisional judgment 6, then judgment 13 and one out, preserving the count. A missed pickup, missed reception or runner already on first prevents the out. The third out selects state 25. Other outs reserve the next batter and select state 14. |

The build runs `BeginDefense` and `CCLDefenseMain::Run` from the supplied APK. Each admitted ground out has two original possession events, the original pass preparation, and a call from `CheckRunnerSafeOrOut` into `JudgeOut` (`0xa1116` to `0xae10c`) for the batter-runner and first baseman. The build extracts the successful and unsuccessful collision inputs for the relevant fielders and phases. No per-query hit/miss answer is embedded. The executable evaluates those inputs in order. The resource stores the runner's initial position, base, destination and speed. Windows computes every stride up to reception. In the original update order the first baseman checks for possession before the runner moves on that frame.

## Coverage and limits

The extractor evaluates the first three shuffled variants of ground-ball groups 3 through 5, both practice batters and all three starting out counts. The ground-out test replays the APK from a mixed count in lineup slot nine and compares possession, run of play, minimap, scoreboard flags, lineup wrap and third outs. It also disables the first baseman's reception and separately increases the runner's speed so he beats the same throw. Neither case can add an out.

Group 3, order 2 distinguishes the two batters. On Ara's run the runner reaches first on frame 30, one frame before the throw arrives. On Medica's run the throw arrives on frame 31 with the runner still short of the bag. The APK's runner manager reports one runner on first for Ara and zero runners for Medica after defense ends. Only the latter case is a supported ground out. Original safe outcomes, including Ara's, remain unresolved in the practice executable until it can carry the runner into the next appearance.

The fielding minimap, defender choices and throw trajectory are recorded from the original defense. The next step is to apply the safe call and preserve first-base occupancy through the next pitch. Arbitrary-seed rebounds, a full opposing half and the final game score remain open.
