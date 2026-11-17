# Checkpoint 6: original pitch-curve recovery

The menu preview was a reconstruction and did not demonstrate gameplay fidelity.
This checkpoint changes focus to recovering original gameplay calculations.
It contains source and test evidence, not a new playable Windows build.

## Implemented and verified

- Native C port of `CCLSpline::Bezier`, original ELF entry `0xb2601`.
- Original Q18 integer arithmetic, rounded Bernstein basis, and all five timing modes.
- Original `CLMath::xSin` lookup values at ELF address `0x1c28ac`.
- Decoder for `assets/data/pitch.zt1`: 369 records in 22 groups, with checked
  compressed size, uncompressed size, record sizes, and group boundaries.
- 359 records use Bezier; 10 use Cardinal and remain unported.
- Recovered decompiler research for 85 gameplay-related functions in
  `gameplay-analysis/` (research output, not buildable source).

The native C generator matched the original ARM generator byte for byte:

- 420 synthetic cases, 8,610 output vertices, across five timing modes,
  1–50 control points, 2/3/17/60 frames, and phases 0/17/90 degrees.
- All 359 extracted Bezier records at their base frame counts: 5,675 vertices.
- Original routine return, unchanged input, and output guard bytes were checked.
- Unsupported input sizes/modes/phases are rejected without output writes.

No arithmetic or gameplay calls were mocked during those comparisons. Unicorn
executes original ARM only in the development test. The native implementation
has no emulator dependency. It has been compiled and executed on the x86-64
development host; it is not yet integrated into the Windows application.

## What this proves and what it does not

This proves that one original pitch-path component can be recovered faithfully.
Extracted curve records were evaluated before the world-space transformations
performed by `CCLPitch::UpdatePitch`. These are not final on-screen trajectories.
The tests do not establish correct in-game pitch selection, animation, duration,
camera position, swing timing, contact outcomes, fielding, or match progression.
Synthetic timing modes do not establish which modes the game actually selects.

A complete faithful port remains unproven. The named functions and successful
component comparisons justify continuing, but they do not support a completion
date or a claim that a full port is close.

## Next milestone

Recover the remaining path method and `UpdatePitch` positioning/matrix dependencies,
then project a real selected pitch into a native scene. Compare a complete pitch
against original state/output before integrating batting and contact outcomes.
Keep the original requested arrow/Space/mouse controls. Do not expand the
placeholder menu as a substitute for this gameplay proof.

## Reproduce tests

Dependencies: Python 3, pyelftools, unicorn, GCC (or compatible C compiler).
Provide the II APK and extract `lib/armeabi/libgameDSO.so` to `/tmp/baseball-game.so`.

```sh
python extract_pitch.py /path/to/baseball-superstars-ii.apk pitch-records.json
gcc -std=c11 -O2 -Wall -Wextra -Werror -shared -fPIC src/pitch_curve.c -o /tmp/bs2-pitch-curve.so
python test_pitch_curve.py /tmp/baseball-game.so /tmp/bs2-pitch-curve.so
```

The raw APK and original native library are not included in this checkpoint.
Prior source and research are included to preserve continuity. The earlier menu
preview binary is unchanged and is not included as a new gameplay build.
