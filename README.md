# 🔄 Push Swap

![C](https://img.shields.io/badge/language-C-blue.svg)
![42 School](https://img.shields.io/badge/school-42-brightgreen.svg)
![Status](https://img.shields.io/badge/status-complete-success.svg)

A highly optimized sorting algorithm implementation that sorts integers using two stacks (`stack_a` and `stack_b`) with a limited set of operations. This project challenges you to sort data with the minimum number of moves possible.

## 🎯 Overview

Push Swap is a sorting algorithm project that simulates the process of sorting a stack of integers using only specific stack operations. The goal is to sort the numbers in ascending order in `stack_a` using the minimum number of operations possible.

### The Challenge
- You have two stacks: `stack_a` (contains random integers) and `stack_b` (empty)
- You can only use specific operations (push, swap, rotate)
- Sort all numbers in `stack_a` in ascending order
- Use the fewest operations possible

## ✨ Features

- **Multi-algorithm approach**: Different strategies for different input sizes
- **Chunk sorting**: Efficient algorithm for large datasets (100+ numbers)
- **Small stack optimization**: Specialized algorithms for 2-10 numbers
- **Input validation**: Comprehensive error handling for invalid inputs
- **Memory management**: Proper cleanup and leak prevention
- **Performance optimized**: Achieves excellent operation counts

## 🧠 Algorithm Strategy

The implementation uses different algorithms based on input size:

### For 2 numbers:
- Simple swap if needed

### For 3 numbers:
- Hardcoded optimal solutions for all permutations

### For 4-10 numbers:
- Push smallest numbers to `stack_b`
- Sort remaining 3 in `stack_a`
- Push back from `stack_b` in order

### For 11+ numbers:
- **Chunk sorting algorithm**
- Divide numbers into chunks (5 for ≤100, 11 for >100)
- Process chunks systematically
- Return elements to `stack_a` in sorted order

## 🚀 Installation

### Prerequisites
- C compiler
- Make
- Unix-like operating system (Linux/macOS)

### Build from Source

```bash
# Clone the repository
git clone https://github.com/peda-cos/push_swap.git
cd push_swap

# Build the project
make

# Clean build files (optional)
make clean
```

The build process will:
1. Compile the custom `libft` library
2. Compile all push_swap source files
3. Link everything into the `push_swap` executable

### 🛠️ Build Commands

| Command | Description |
|---------|-------------|
| `make` | Build the project |
| `make clean` | Remove object files |
| `make fclean` | Remove object files and executable |
| `make re` | Clean rebuild |

## 💻 Usage

### Basic Usage

```bash
# Sort a list of integers
./push_swap 3 1 4 1 5 9 2 6

# Using negative numbers
./push_swap -3 0 1 -1 5

# Large dataset
./push_swap $(seq 1 100 | shuf)
```

### Input Requirements ⚠️

- **Integers only**: Must be within `INT_MIN` to `INT_MAX` range
- **No duplicates**: Each number must be unique
- **Space-separated**: Numbers separated by spaces
- **Valid format**: Only digits, spaces, and +/- signs

### Error Cases

The program outputs `"Error\n"` to stderr for:
- Non-integer arguments
- Duplicate numbers
- Numbers outside integer range
- Invalid characters in input

### Examples

```bash
# ✅ Valid inputs
./push_swap 2 1 3
./push_swap 0
./push_swap -1 -2 -3

# ❌ Invalid inputs
./push_swap 1 2 3 1    # Duplicate
./push_swap 1 abc      # Non-integer
./push_swap           # No arguments (exits silently)
```

## 🔧 Available Operations

| Operation | Description | Output |
|-----------|-------------|---------|
| `sa` | Swap first 2 elements of stack_a | `sa` |
| `sb` | Swap first 2 elements of stack_b | `sb` |
| `ss` | `sa` and `sb` at the same time | `ss` |
| `pa` | Push first element of stack_b to stack_a | `pa` |
| `pb` | Push first element of stack_a to stack_b | `pb` |
| `ra` | Rotate stack_a (first element becomes last) | `ra` |
| `rb` | Rotate stack_b (first element becomes last) | `rb` |
| `rr` | `ra` and `rb` at the same time | `rr` |
| `rra` | Reverse rotate stack_a (last element becomes first) | `rra` |
| `rrb` | Reverse rotate stack_b (last element becomes first) | `rrb` |
| `rrr` | `rra` and `rrb` at the same time | `rrr` |

## 📊 Performance

### Operation Count Targets 🎯

| Input Size | Excellent | Good | Acceptable |
|------------|-----------|------|------------|
| 3 numbers | ≤3 ops | ≤3 ops | ≤3 ops |
| 5 numbers | ≤12 ops | ≤12 ops | ≤12 ops |
| 100 numbers | ≤700 ops | ≤900 ops | ≤1500 ops |
| 500 numbers | ≤5500 ops | ≤7000 ops | ≤11500 ops |

### Benchmarking

```bash
# Test with random 100 numbers
ARG=$(seq 1 100 | shuf | tr '\n' ' '); ./push_swap $ARG | wc -l

# Test with random 500 numbers
ARG=$(seq 1 500 | shuf | tr '\n' ' '); ./push_swap $ARG | wc -l

# Multiple tests for average
for i in {1..10}; do
  ARG=$(seq 1 100 | shuf | tr '\n' ' ')
  echo "Test $i: $(./push_swap $ARG | wc -l) operations"
done
```

## 📁 Project Structure

```
push_swap/
├── 📄 README.md                    # This file
├── 📄 Makefile                     # Build configuration
├── 📄 push_swap.h                  # Main header file
├── 📄 main.c                       # Program entry point
├── 📄 push_operations.c            # Push operations (pa, pb)
├── 📄 swap_operations.c            # Swap operations (sa, sb, ss)
├── 📄 rotate_operations.c          # Rotate operations (ra, rb, rr)
├── 📄 reverse_rotate_operations.c  # Reverse rotate operations
├── 📄 sorting_algorithms.c         # Main sorting logic
├── 📄 sorting_helpers.c            # Index assignment utilities
├── 📄 sorting_utils.c              # Helper functions
├── 📄 chunk_sort.c                 # Chunk sorting algorithm
├── 📄 utils.c                      # Utility functions
└── 📁 libft/                       # Custom C library
    ├── 📄 libft.h                  # Library header
    ├── 📄 Makefile                 # Library build config
    └── 📄 *.c                      # Library implementation files
```

### 🔍 Key Components

- **`main.c`**: Input validation and program flow
- **`sorting_algorithms.c`**: Core sorting logic dispatcher
- **`chunk_sort.c`**: Advanced algorithm for large datasets
- **`*_operations.c`**: Implementation of stack operations
- **`libft/`**: Custom library with linked lists and utilities

### Checker Program (if available)

```bash
# If you have a checker program
ARG="3 1 2"; ./push_swap $ARG | ./checker $ARG
```

## 📚 Additional Resources

- [Sorting Algorithms Visualization](https://visualgo.net/en/sorting)
- [Stack Data Structure](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))

## 📝 License

This project is part of the 42 School curriculum. Feel free to use it for educational purposes.

---

**Happy Sorting!** 🎉

*Made with ❤️ by [peda-cos](https://github.com/peda-cos)*
