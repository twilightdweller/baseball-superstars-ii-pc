# Checkpoint 10: Windows baseline and original pitch-result helpers

The entire existing checkpoint-9 build and comparison suite now passes locally
on Windows. Python 3.11.9, pyelftools 0.33, Unicorn 2.1.4, Pillow 10.1.0, and
MSVC 14.43.34808 were used. The recovered C was rebuilt with /std:c11 /O2 /W4
/WX /MT. ARM runs only as a development oracle, never in the native viewer.

## New recovered code

src/pitch_rules.c implements these original helpers. Addresses below are ELF
entry points including the Thumb bit, not Ghidra's additional 0x10000 base.

| Native helper | Original function | ELF entry | Comparisons |
| --- | --- | --- | ---: |
| bs2_pitch_judge | CBBGRuleEngine::PitchJudge | 0xbe219 | 1,120 |
| bs2_bound_judge | CBBGRuleEngine::BoundJudge | 0xbe35d | 832 |
| bs2_play_is_foul | CBBGPlayData::IsFoul | 0xd7f7d | 1,088 |
| bs2_reset_sb | CBBGPlayData::ResetSB | 0xd7ed5 | 512 |
| bs2_reset_sbo | CBBGPlayData::ResetSBO | 0xd7f01 | 512 |
| bs2_increment_strike_to_two | CBBGPlayData::InccStrikeTo2S | 0xd8221 | 512 |

All 4,576 comparisons passed. They check defined return values, entire object
bytes, guards, normal ARM return, and unchanged rule-engine objects. Every
PitchJudge result (1, 2, 3, 4, 5) and BoundJudge result (0, 6, 7, 8, 10, 11,
12, 13) was reached. Result numbers remain untranslated in the native API;
the match handler and result-label mapping have not been ported.

The count bytes retain the original signed-byte comparisons. Tests cover every
possible count-byte value, Boolean and non-Boolean flag values, signed 32-bit
boundaries, and explicit decision branches. ResetSB includes its original
per-pitch flag writes at 0x14-0x17 and 0x164-0x167; ResetSBO additionally clears
byte 6. The native API operates on the ARM play-data byte layout with at least
0x168 bytes supplied by the caller, without embedding native pointers.

PitchJudge and BoundJudge follow the preserved decompiler research, checked
against the actual ARM routines. IsFoul and the count helpers were recovered
from their original Thumb instruction bytes and verified by differential tests.
No original gameplay calls or arithmetic were mocked. Original BoundJudge
calls original IsFoul; original ResetSBO calls original ResetSB.

## Reproduce

From the repository root:

```powershell
python verify_windows.py
```

After building, run only the new comparisons from source:

```powershell
python test_pitch_rules.py ../build/libgameDSO.so ../build/bs2-pitch-rules.dll
```

The runner writes build/results.json and a log per build/test. Full-suite
output for this checkpoint is also saved in build/verification-latest.log.
Existing reference tests and recovered C implementations remain intact.

## Scope and next work

This is additional verified native logic, not a playable at-bat. The new helpers
are not connected to the diagnostic viewer. Controlled play-data objects do
not establish live-match initialization, correct event ordering, or full count
progression. Do not treat InccStrikeTo2S as the complete strikeout transition.

The next integration targets are original pitch event handling, swing/contact
decisions, and the pitch-result handler that consumes the result codes and
advances the plate appearance. Relevant original symbols are:

- CBBGGameRun::EVENT_HANDLER_GSTATE_PITCH, ELF 0x177f01, 1,132 bytes.
- CBBGGameRun::INIT_HANDLER_GSTATE_PITCH_JUDGE, ELF 0x169f2d, 844 bytes.
- CBBGGameRun::EVENT_HANDLER_GSTATE_PITCH_JUDGE, ELF 0x169135, 292 bytes.
- CBBGGameRun::GetBattingTiming, ELF 0x163e61, 56 bytes.

These symbol addresses and sizes were read from the supplied ELF. Listing them
is not a claim that their behavior has been recovered. Complete match timing,
input/contact, animation, fielding and progression remain outstanding.

An optional Capstone installation attempt in this session failed with pip's
"No matching distribution found" message. Capstone was not required for the
completed comparisons. No GUI run or sanitizer execution is claimed.
