*This project has been created as part of the 42 curriculum by peda-cos*

# push_swap

A sorting algorithm project from the 42 curriculum. Sorts a sequence of integers using two stacks and a restricted set of operations, outputting the minimal sequence of moves.

## Description

`push_swap` takes a list of integers as arguments and prints the operations needed to sort them in ascending order on stack A, using only stack B as auxiliary storage and 11 allowed operations.

The bonus `checker` program reads a sequence of operations from stdin and verifies whether they correctly sort the given list.

### Allowed Operations

| Operation | Effect |
|-----------|--------|
| `sa` | Swap top 2 elements of A |
| `sb` | Swap top 2 elements of B |
| `ss` | `sa` and `sb` simultaneously |
| `pa` | Push top of B onto A |
| `pb` | Push top of A onto B |
| `ra` | Rotate A (top → bottom) |
| `rb` | Rotate B (top → bottom) |
| `rr` | `ra` and `rb` simultaneously |
| `rra` | Reverse rotate A (bottom → top) |
| `rrb` | Reverse rotate B (bottom → top) |
| `rrr` | `rra` and `rrb` simultaneously |

## Algorithm

Uses the **Turk Algorithm** (greedy cost-based selection):

1. Push all elements except 3 from A to B
2. Sort the remaining 3 in A with at most 2 operations
3. For each element in B, compute the actual cost (in moves) to insert it into the correct position in A, accounting for simultaneous rotations (`rr`/`rrr`)
4. Execute the cheapest insertion first, repeat until B is empty
5. Rotate A so the minimum element is on top

**Benchmarks:** ≤ 635 ops for 100 numbers · ≤ ~5470 ops for 500 numbers

## Instructions

```bash
# Build push_swap
make

# Build checker (bonus)
make bonus

# Clean object files
make clean

# Full clean
make fclean

# Rebuild
make re
```

### Usage

```bash
# Sort numbers
./push_swap 3 1 4 1 5 9 2 6

# Verify with checker
./push_swap 3 1 4 5 2 | ./checker 3 1 4 5 2
# → OK

# Quoted string of numbers
./push_swap "3 1 4 5 2"
```

### Edge cases handled

- No arguments → no output
- Already sorted → no output  
- Invalid input (non-integer, overflow, duplicate) → `Error` on stderr

## Resources

- [Push_swap visualizer](https://github.com/o-reo/push_swap_visualizer)
- [The Turk Algorithm explained](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)
- [Sorting algorithms — Big-O complexity cheat sheet](https://www.bigocheatsheet.com/)
- [Wikipedia — Sorting algorithm](https://en.wikipedia.org/wiki/Sorting_algorithm)

### AI Usage

AI (Claude) was used in this project in the following ways:

- **Documentation**: Drafting and structuring the `README.md` to comply with the 42 subject requirements.
- **Debugging assistance**: Identifying off-by-one errors in rotation cost calculations and edge cases in the 3-element sort.

The core algorithm design (Turk Algorithm), data structures, and all `.c`/`.h` implementation were written by the student. AI was not used to generate production code.
