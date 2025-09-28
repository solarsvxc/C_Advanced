# MEMORY ERROR SIMULATOR IN C

## Description
`memory_lab` is a C++ program demonstrating **common memory errors**:
- `stack_overflow` — infinite recursion leading to stack overflow.
- `out_of_memory` — continuous allocation of large memory blocks until system throws `bad_alloc`.
- `memory_leak` — memory is allocated but never released, causing a memory leak.

Purpose: illustrate behavior, consequences, and debugging techniques for each type of memory error.

---

## File Contents

- **stack_overflow(int count)**  
  Recursively calls itself without a stopping condition. Prints `"Stack over flow<count>"` for each call. Eventually crashes due to stack overflow (segmentation fault).

- **out_of_memory()**  
  Continuously allocates a huge array (`int[1000000000]`). When memory allocation fails, `new` throws `bad_alloc`, which is caught and prints `"Out of memory"`.

- **memory_leak()**  
  Allocates an array of `int[5000]` but does not delete it. Memory is leaked. If called repeatedly, memory consumption increases.

- **main()**  
  Simple interface that reads user input and executes the corresponding demo. Input must match the expected strings (e.g., `./memory_lab stack_overflow`).

---

## Build Instructions (Linux/macOS/WSL)

```bash
g++ -std=c++17 -O2 -Wall -Wextra -o memory_lab memory_lab.cpp
