
# Self Test — C code and test files

This folder contains small self-test examples and a minimal test harness for learning C development and embedded-style command dispatch patterns.

Use this README as a quick reference for what is included, how to build and run the tests on a host machine, how to adapt them for a cross-compile/embedded target, and guidance for adding new test cases.

## Purpose

- Provide readable, compact C examples that demonstrate self-test patterns and a simple command-dispatcher style module.
- Offer a minimal way to compile and run tests on the host (Windows / Linux) to validate logic before porting to a microcontroller.

## Repository layout (relevant items)

- `Command Dispatcher/`
	- `command_dispatcher.c` — example implementation of a command dispatcher (parse/dispatch pattern).
	- `Readme.md` — notes specific to the command dispatcher example (if present).
- `Readme.md` (this file) — overview and instructions for the Self Test examples.

If you add new tests or example modules, create a subfolder and include a short README explaining the interface and expected behaviour.

## Quick contract

- Inputs: small text commands (for dispatcher) or simple function inputs in test harness.
- Outputs: console/log text showing pass/fail and simple return codes.
- Error modes: invalid commands, null pointers, out-of-range values. Tests should assert behaviour for these.

## Build and run (host, GCC/MinGW/Clang)

These steps assume you have a C compiler installed (GCC via MinGW-w64 on Windows, or GCC/Clang on Linux/macOS). From PowerShell you can use the following example commands.

1) Build a simple test executable (adjust file names if your sources differ):

```powershell
# Compile a single C source into test.exe
gcc -std=c11 -Wall -Wextra -O2 -I"Command Dispatcher" -o test.exe "Command Dispatcher/command_dispatcher.c"

# If you have a separate test driver (e.g. test.c) compile together:
gcc -std=c11 -Wall -Wextra -O2 -I"Command Dispatcher" -o test.exe "Command Dispatcher/command_dispatcher.c" test.c
```

2) Run the test program:

```powershell
.\test.exe
```

Notes:
- If you target an embedded platform, replace `gcc` with the appropriate cross-compiler (for example `arm-none-eabi-gcc`) and adapt linker scripts and startup code.
- Use `-DDEBUG` to enable extra debug prints if the code supports it.

## Example test cases

The repository intentionally uses tiny, easy-to-follow examples. Suggested tests to include in `test.c` or a small test harness:

- Happy-path command: send a valid command string and expect a correct response/return code.
- Invalid command: pass an unknown command and expect a defined error code or no-op.
- Boundary inputs: empty string, very long command, NULL pointer (if the API accepts pointers) — confirm graceful failure.
- State tests: if the dispatcher modifies state, test sequence of commands and verify the final state.

Expected output should be printed to the console showing PASS/FAIL for each case and a final summary (e.g., "3 tests run, 3 passed, 0 failed").

## Debugging and troubleshooting

- If compilation fails with missing headers or symbols, check that the `-I` include path matches the folders where headers live.
- For Windows, ensure MinGW-w64 or MSYS2 is installed and on PATH when using `gcc` from PowerShell.
- For segmentation faults, run the binary under a debugger (gdb) or add printf logging to narrow down the failing call.

## Adding tests and CI

- Keep tests small and deterministic. Favor table-driven tests where possible.
- Consider integrating a lightweight unit test framework (Unity, CMock) if the number of tests grows.
- For continuous integration, add a simple build script or GitHub Actions workflow that compiles the test executable and runs it. Exit with non-zero status on test failures.

## Contributing

- Add a folder per new example with source, a small README, and a test-driver.
- Name test drivers `test_*.c` and keep them self-contained.

## License

This folder follows the repository’s license. If you add third-party code, include appropriate license headers.

## Contact / Notes

If you want, I can:
- add a ready-to-run `test.c` harness that exercises `command_dispatcher.c` and prints a pass/fail summary;
- create a simple `Makefile` or PowerShell build script to automate compile+run;
- convert the tests to use Unity and add a basic GitHub Actions workflow to run them on push.

Tell me which of the above you'd like and I'll add it.

