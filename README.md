# Push Swap

A highly efficient sorting algorithm implementation using two stacks and a limited set of operations. This project is part of the 42 School curriculum and challenges students to sort data with optimal performance using minimal operations.

## 📋 Table of Contents

- [About](#about)
- [Algorithm Overview](#algorithm-overview)
- [Technology Stack](#technology-stack)
- [Project Structure](#project-structure)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Operations](#operations)
- [Sorting Strategies](#sorting-strategies)
- [Performance](#performance)
- [License](#license)

## 🎯 About

**Push Swap** is a sorting algorithm project that sorts a stack of integers using only two stacks (A and B) and a specific set of operations. The goal is to sort the numbers in ascending order in stack A with the minimum number of operations possible.

### Project Objectives

- Implement an efficient sorting algorithm with minimal operations
- Understand and apply algorithm optimization techniques
- Work with data structures (stacks/linked lists)
- Master memory management in C
- Practice algorithmic thinking and problem-solving

## 🧠 Algorithm Overview

The project implements multiple sorting strategies based on stack size:

- **2 elements**: Single swap operation
- **3 elements**: Optimized hardcoded sorting
- **4-10 elements**: Small stack algorithm (selective push to stack B)
- **11+ elements**: Chunk sort algorithm with index-based partitioning

The chunk sort algorithm divides the stack into chunks, processes each chunk by pushing elements to stack B, and then reconstructs the sorted stack by pushing elements back to stack A in descending order.

## 🛠 Technology Stack

- **Language**: C (C99 standard)
- **Compiler**: gcc/clang
- **Build System**: Make
- **Libraries**: Custom libft library
- **Development Standards**: 42 School Norminette v3

### Dependencies

- **libft**: Custom C standard library implementation
  - Linked list operations
  - String manipulation
  - Memory management utilities
  - Custom printf implementation

## 📁 Project Structure

```
push_swap/
├── push_swap.h              # Main header file with function prototypes
├── main.c                   # Entry point, input validation, and stack initialization
├── Makefile                 # Build configuration
│
├── Operations/
│   ├── push_operations.c         # pa, pb operations
│   ├── swap_operations.c         # sa, sb, ss operations
│   ├── rotate_operations.c       # ra, rb, rr operations
│   └── reverse_rotate_operations.c  # rra, rrb, rrr operations
│
├── Sorting/
│   ├── sorting_algorithms.c      # Main sorting logic and algorithm selection
│   ├── sorting_helpers.c         # Helper functions for sorting operations
│   ├── sorting_utils.c           # Utility functions (find min/max, positioning)
│   └── chunk_sort.c              # Chunk-based sorting algorithm for large stacks
│
├── Utils/
│   └── utils.c                   # Error handling, validation, and utility functions
│
└── libft/                        # Custom C library
    ├── libft.h                   # Library header
    ├── Makefile                  # Library build configuration
    └── [various .c files]        # Library implementations
```

## 🚀 Getting Started

### Prerequisites

- GCC or Clang
- Make
- Unix-like operating system (Linux, macOS)

### Installation

1. Clone the repository:
```bash
git clone https://github.com/peda-cos/push_swap.git
cd push_swap
```

2. Compile the project:
```bash
make
```

This will compile both the libft library and the push_swap executable.

### Build Commands

```bash
make        # Build the project
make clean  # Remove object files
make fclean # Remove object files and executable
make re     # Rebuild the project from scratch
```

## 💻 Usage

### Basic Usage

```bash
./push_swap [numbers...]
```

The program takes a list of integers as arguments and outputs the sequence of operations needed to sort them.

### Examples

```bash
# Sort three numbers
./push_swap 3 2 1
# Output: sa ra

# Sort five numbers
./push_swap 5 4 3 2 1
# Output: pb pb pb sa pa pa pa

# Sort random numbers
./push_swap 42 17 89 3 56
```

### Input Validation

The program validates input and handles:
- ✅ Integers within INT_MIN to INT_MAX range
- ✅ Duplicate detection
- ✅ Invalid number format detection
- ❌ Outputs "Error" to stderr for invalid input

## 🔄 Operations

The program can perform the following operations:

### Swap Operations
- `sa` - Swap the first two elements of stack A
- `sb` - Swap the first two elements of stack B
- `ss` - Execute `sa` and `sb` simultaneously

### Push Operations
- `pa` - Push the top element from stack B to stack A
- `pb` - Push the top element from stack A to stack B

### Rotate Operations
- `ra` - Rotate stack A upward (first element becomes last)
- `rb` - Rotate stack B upward
- `rr` - Execute `ra` and `rb` simultaneously

### Reverse Rotate Operations
- `rra` - Rotate stack A downward (last element becomes first)
- `rrb` - Rotate stack B downward
- `rrr` - Execute `rra` and `rrb` simultaneously

## 🎲 Sorting Strategies

### Three Elements Algorithm
Hardcoded optimal solution for all 6 possible permutations.

### Small Stack Algorithm (4-10 elements)
1. Push minimum elements to stack B
2. Sort remaining 3 elements in stack A
3. Push elements back to stack A

### Chunk Sort Algorithm (11+ elements)
1. **Index Assignment**: Assign sorted indices to each element
2. **Chunk Division**: Divide the stack into 5 chunks (≤100) or 11 chunks (>100)
3. **Push to B**: Process each chunk, pushing elements to stack B with rotation optimization
4. **Reconstruct**: Push elements back to stack A in descending order (largest first)

#### Chunk Size Calculation
- Stack size ≤ 100: 5 chunks
- Stack size > 100: 11 chunks

This approach minimizes operations by reducing the problem space and leveraging index-based positioning.

## 📊 Performance

The implementation achieves the following performance benchmarks:

| Stack Size | Maximum Operations | Average Operations |
| ---------- | ------------------ | ------------------ |
| 3          | 3                  | 2                  |
| 5          | 12                 | 8                  |
| 100        | ~700               | ~550               |
| 500        | ~5500              | ~5700              |

> **Note**: Performance may vary based on input distribution. Random inputs typically achieve better than worst-case performance.

### Optimization Techniques

- Index-based sorting to avoid repeated comparisons
- Chunk partitioning for divide-and-conquer approach
- Strategic rotation to minimize operations
- Median-based element positioning within chunks

## 🧪 Testing

You can test the program with various tools:

### Manual Testing
```bash
# Test with specific numbers
./push_swap 4 67 3 87 23

# Test with random numbers (using ARG)
ARG=$(seq 1 100 | shuf | tr '\n' ' '); ./push_swap $ARG
```

### Operation Counter
```bash
# Count operations
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
```

### Visualizer Tools
Consider using community-made visualizers to see the sorting process in action:
- [push_swap_visualizer](https://github.com/o-reo/push_swap_visualizer)
- [push_swap_tester](https://github.com/lmalki-h/push_swap_tester)

## 🤝 Contributing

This is a 42 School project and follows the school's academic policies. While direct contributions are not accepted, feedback and suggestions are welcome!

### Coding Standards

The project adheres to the 42 School Norminette v3:
- Maximum 25 lines per function
- Maximum 80 columns per line
- Specific formatting and naming conventions
- Forbidden functions: printf (custom implementation used)

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

Copyright (c) 2025 Pedro Monteiro

---

<div align="center">

**Made with ❤️ at [42 São Paulo](https://www.42sp.org.br/)**

*This project is part of the 42 School common core curriculum*

</div>
