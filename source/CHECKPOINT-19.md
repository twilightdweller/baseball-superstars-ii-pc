# Checkpoint 19. A single followed by a force play

Seed 1184 produces Ara's ground-ball single followed by Medica's grounder to the pitcher when both swing immediately at the default pitch. The second play uses the original group's first variant (group 3, order 0). The same grounder produces different throws depending on the number of outs.

| Starting outs | Possession and force decisions | End of defense |
| --- | --- | --- |
| 0 | Pitcher fields on tick 11 and begins throwing on 15. Second baseman forces Ara on 21, starts the relay on 23, and first baseman retires Medica on 31. | Tick 45. Two outs, empty bases, next batter reserved. |
| 1 | Same two force outs on ticks 21 and 31. | Tick 52. The third out ends the half. |
| 2 | Pitcher fields on 11 and begins throwing to first on 15. First baseman retires Medica on 22. Ara reaches second during the runner update on that tick. | Tick 43. Three outs, no runs. The original runner manager retains Ara at second through this boundary. A fresh practice half clears the bases. |

## What is native

The build advances the original lineup and runner manager after a single, then calls the APK's pitch-session reset, batting-pattern selection and defense entry with Ara on first. The original defense supplies the choice of base, receiver bounds, throw paths, cleanup timing and minimap. The lookup requires the runner to be the previous batting slot, Ara running, Medica batting, and the verified ground-ball variant.

Windows advances both runners using the original level-ground movement rule, tests the pitcher's pickup and each receiver's collision, and checks runner arrival before awarding each force. Defender actions precede the runner update in each frame. On a double play, the original runner manager clears first base on tick 29, after the force at second. With two outs, native arrival moves Ara from first to second on tick 22. Repeated or skipped presentation frames cannot add duplicate outs.

## Verification

Six reference runs cover the three starting out counts after two preceding single variants. They compare both paths through each force, throw contacts, scoreboard calls, each occupied base, original minimap commands and the reserved batting slot. Disabling a player's collision or changing a runner's speed tests that the recorded play cannot award an unsupported out. The swing comparison also follows seed 1184 through Ara's contact and Medica's contact with the original runner manager reporting first occupied.

The executable covers this specific occupied-base grounder. A four-ball walk still needs forced advancement and a connected next batter. Other fielding decisions, scoring, opponent innings and the full game remain open.
