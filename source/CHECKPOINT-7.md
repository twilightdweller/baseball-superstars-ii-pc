# Checkpoint 7: remaining pitch curves and coordinate transforms

Both curve-generation methods used by all 369 extracted pitch records now have
native C implementations. The original matrix update, point transformation,
and screen projection routines also have native implementations.

This is a source checkpoint, not a new playable Windows build.

## Changes

- `src/pitch_curve.c`: added Cardinal interpolation, preserving integer rounding,
  32-bit wraparound, endpoint behavior, and the original tangent threshold.
- `src/projection.c` and `.h`: added scale/rotation/translation matrix updates,
  homogeneous point transforms, and projection to screen coordinates.
- `test_cardinal.py` and `test_projection.py`: compare native outputs directly
  against original APK machine code. Research exports include the newly inspected
  matrix and arctangent routines.

## Verification

| Comparison | Cases | Result |
|---|---:|---|
| Extracted Cardinal records | 10, producing 182 vertices | Exact match |
| Synthetic Cardinal curves | 90, producing 3,636 vertices | Exact match |
| Matrix point transforms | 1,200 | Exact match |
| Screen projections | 1,200 | Exact match |
| Scale/rotation/translation matrix updates | 1,200 | Exact object writes |
| Existing synthetic Bezier curves | 420 | Exact match |
| Existing extracted Bezier records | 359 | Exact match |

The native code compiled with strict warnings and also passed the tests with
UndefinedBehaviorSanitizer enabled. Tests check output guards, unchanged inputs,
normal return from original routines, invalid size rejection, and native in-place
point transforms. Matrix tests include randomized signed 32-bit values, identity
matrices, zero homogeneous divisors, zero projection depth, and rotation boundaries.
These are sampled and boundary tests, not exhaustive coverage of every integer.

Original Cardinal execution uses a test allocator instead of Android allocation:
only `operator new[]` and `operator delete[]` are intercepted, with allocation sizes,
valid frees, and balanced lifetime checked. Interpolation and arithmetic execute
unchanged. Matrix/projection comparisons do not intercept arithmetic or gameplay.
Original ARM execution is confined to development tests. Native C has no emulator
dependency and was executed on the x86-64 development host.

## Remaining gap

The complete `CCLPitch::UpdatePitch` pipeline is not yet ported or verified.
It positions the input curve using pitcher/stadium state, rotates and stretches
it toward the target, invokes interpolation, and extends the resulting path.
The camera configuration used in an actual match also remains to be recovered.
The verified transforms have been tested with controlled inputs, not a captured
live-match camera. No claim of an original on-screen pitch or playable scene is made.

The next implementation target is that positioning pipeline and its arctangent
lookup dependency, followed by a complete pitch comparison using recovered scene
state. Batting, contact outcomes, fielding, and match progression remain unported.

## Reproduce

Run from this source directory with GCC, Python, pyelftools, and unicorn available.
Supply the original II native library extracted from the user's APK.

```sh
gcc -std=c11 -O2 -Wall -Wextra -Werror -shared -fPIC src/pitch_curve.c -o /tmp/bs2-pitch-curve.so
gcc -std=c11 -O2 -Wall -Wextra -Werror -shared -fPIC src/projection.c -o /tmp/bs2-projection.so
python test_cardinal.py /tmp/baseball-game.so /tmp/bs2-pitch-curve.so
python test_pitch_curve.py /tmp/baseball-game.so /tmp/bs2-pitch-curve.so
python test_projection.py /tmp/baseball-game.so /tmp/bs2-projection.so
```

For the sanitizer build replace `-O2` with
`-O1 -g -fsanitize=undefined -fno-sanitize-recover=all` in the compile commands.
The archive includes prior source and research for continuity; APKs and executable
previews are omitted. Earlier checkpoint documents describe their historical state.
