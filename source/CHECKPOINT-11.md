# Checkpoint 11: original pitch-result flow and batting timing

This checkpoint adds native C implementations of three original routines:

| Routine | Original ELF entry | Differential comparisons |
| --- | --- | ---: |
| CBBGFlowMgr::NextStateAtPitchJudge | 0xcbfe9 | 1,808 |
| CBBGPlayData::IsGameOver | 0xd7f99 | 2,048 |
| CBBGGameRun::GetBattingTiming | 0x163e61 | 2,609 |

The new tests pass 6,465 comparisons. Source is in src/pitch_flow.c and .h;
test_pitch_flow.py runs the supplied APK's ARM code as the reference.
The full Windows runner also passes all 36 build, extraction, fixture and test
checks after the correction, using the existing MSVC /W4 /WX configuration.

## Recovered behavior

The flow function returns the original numeric states 14, 16, 24, 25, or 26,
depending on play data. It preserves the signed-byte checks on mode, result,
outs, innings and score fields. Mode 7 includes original flag transfers, byte
counter wrap, threshold decisions, and the additional-attempt branch. The
first six recovered threshold entries at ELF 0x1c468c are checked against the
reference image: 700, 1100, 1500, 1900, 2300, and 99999.

The native interface rejects an index outside those six recovered entries only
on a path that would read the threshold table. Rejection returns -1 without
object writes or callbacks. This is an intentional input guard; it is not a
claim that the original routine rejects those inputs. No original table bounds
check was observed. The supported domain is explicit in the native interface.

The game-over predicate executes unchanged inside the original flow comparison.
The native version reads the same byte fields and has separate boundary tests.

Batting timing returns 100 for equal frame values, 75 for a one-frame difference,
and 0 otherwise, retaining original 32-bit wraparound. This is the original
timing-value helper, not the complete hit/contact calculation or an inferred
probability of contact.

## Verification boundaries

Statistics ProcJudge and mission ChkGoalCompleted are supplied through explicit
native callbacks. Their original ARM callees are intercepted in this test;
the tests compare callback order, arguments on the ARM side, return decisions,
entire play-data writes, manager preservation, and buffer guards. Additional
cases give both callbacks matching controlled side effects. No claim is made
that the statistics or mission implementations themselves are recovered.

The callback is required. Production integration must implement those effects;
silently dropping them would not reproduce the original game.

An initial mode-7 comparison found a field-write mismatch in the additional-
attempt branch: the original increments byte 0x33, not byte 0x38. The native
implementation was corrected and the whole new test passed. The instruction
path is preserved in research/checkpoint11/000cbfe8.txt.

## Inspection tooling

tools/inspect_arm_windows.py uses installed MSVC dumpbin to inspect Thumb
functions without installing another disassembler. It wraps unmodified ELF
function bytes in a temporary ARMNT COFF section with the original address.
It does not execute the original code. Literal pools can appear as instructions
in dumpbin output and must be read as data where referenced by literal loads.

The research directory preserves annotated disassembly for the three recovered
routines and the full pitch event, pitch-judge initialization, and pitch-judge
event handlers. These research files are not buildable C implementations.

## Reproduce

From the repository root, run `python verify_windows.py`. It builds the new DLL
and runs the existing suite plus test_pitch_flow.py. After building, the new
test alone can be run from source:

```powershell
python test_pitch_flow.py ../build/libgameDSO.so ../build/bs2-pitch-flow.dll
```

No emulator is added to the Windows application. The existing viewer remains a
pitch-motion diagnostic. GUI execution and sanitizer runs are not claimed.

## Remaining at-bat work

A complete at-bat is still not implemented. The result initializer and event
handler contain additional writes, next-batter requests, runner decisions,
statistics calls, and event dispatch that must be recovered before connecting
the new flow routine. The initializer writes result byte 0x0c, while the flow
routine reads byte 0x0b; do not equate these fields without tracing the intervening
event/statistics path.

The pitch-event handler also depends on original player/skill state, input,
pitch-locus updates and event dispatch. Original GetBattingTiming is only one
dependency. Swing/contact, continuous pitch timing, result application and
plate-appearance progression remain integration targets. No replacement
baseball rules or approximate contact model were introduced.
