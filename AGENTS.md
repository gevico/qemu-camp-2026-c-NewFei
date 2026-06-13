# AGENTS.md — QEMU Camp C Exercises

## Project structure

40 C exercises in `exercises/<name>/`. Test files in `tests/test_<name>.c` using custom framework `checker/test_framework.h`. All autograded via `c-checker`.

## Key commands

```sh
make c-checker           # build the checker (prerequisite for everything)
make check-all           # run all 40 exercises (aliased as `make test`)
make check <name|num>    # single exercise, e.g. `make check 01` or `make check 21_singly_linked_list_josephus`
make hint <name|num>     # show hints for one exercise
make list                # list all exercises with status
make clean               # remove c-checker, .o, test binaries, test_results_summary.json
make watch               # inotify-based re-test loop on file changes
./run.sh <exercise_name> # compile and run a single exercise directly (independent of c-checker)
```

Direct checker usage: `./c-checker check-all`, `./c-checker check <name|num>`, `./c-checker hint <name|num>`, `./c-checker list`.

## Exercise compilation modes

- **01-15**: single `.c` file → compiled directly with `gcc -Wall -Wextra -std=c11 -o <exec> <source>.c`
- **16-40** (except 20): have their own `Makefile` → compiled via `make -C <exercise_dir>`
- **20_mybash**: special multi-file project (`exercises/20_mybash/src/mybash/main.c`, has Makefile); compiled via `make`, tested via shell script

## Mandatory conventions

- Remove `I AM NOT DONE` marker from source files before grading — c-checker skips any file containing it
- Compiler: `gcc -Wall -Wextra -std=c11`
- Code style per `.clang-format`: Google-based, 4-space indent, 120 column limit
- `.editorconfig`: 4-space indent for C, LF, UTF-8
- Some exercises need `-lm` (math library) — c-checker auto-detects `prime` in filename

## Test framework

Tests are standalone C programs in `tests/` that `#include "../checker/test_framework.h"`. They link `../checker/test_framework.c` during compilation. Available macros:

- `ASSERT_TRUE(cond, msg)`, `ASSERT_FALSE(cond, msg)`
- `ASSERT_EQUAL_INT(expected, actual, msg)`
- `ASSERT_EQUAL_STR(expected, actual, msg)`
- `compile_and_run(source, exec, output_buf, size, is_make)` — is_make=0 for 01-15, is_make=1 for 16-40, is_make=2 for 20_mybash
- `file_contains_marker(path, marker)`, `string_contains(haystack, needle)`

## CI

`.github/workflows/opencamp-autograding.yml`: runs `make c-checker && ./c-checker check-all` on push to `main`/`master` or PR. Generates `test_results_summary.json` artifact. Score reporting to OpenCamp requires secrets (`QEMU_CAMP_2026_C_AUTUMN_TOKEN`, `QEMU_CAMP_2026_COURSE_POST_API`, `QEMU_CAMP_2026_C_AUTUMN_COURSE_ID`); skipped on PRs.

## Scoring

40 exercises × 5 pts = 200 max. Results in `test_results_summary.json`.
