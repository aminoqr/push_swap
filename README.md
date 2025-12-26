*This project has been created as part of the 42 curriculum by aasylbye.*

# Push_Swap

## Description

Push_Swap is a sorting algorithm project from the 42 curriculum. The goal is to sort a stack of integers using a limited set of operations, with the objective of achieving the sort in the minimum number of moves possible.

The program receives a list of integers as arguments and outputs a sequence of instructions that will sort them in ascending order. The challenge lies in finding the most efficient combination of operations to minimize the total number of moves.

### Available Operations

| Operation | Description |
|-----------|-------------|
| `sa` | Swap the first two elements of stack A |
| `sb` | Swap the first two elements of stack B |
| `ss` | Execute `sa` and `sb` simultaneously |
| `pa` | Push the top element from stack B to stack A |
| `pb` | Push the top element from stack A to stack B |
| `ra` | Rotate stack A (first element becomes last) |
| `rb` | Rotate stack B (first element becomes last) |
| `rr` | Execute `ra` and `rb` simultaneously |
| `rra` | Reverse rotate stack A (last element becomes first) |
| `rrb` | Reverse rotate stack B (last element becomes first) |
| `rrr` | Execute `rra` and `rrb` simultaneously |

### Algorithm

This implementation uses the **Turk Algorithm**, an efficient sorting approach that:
1. Pushes elements from stack A to stack B while maintaining a relative order
2. Calculates the "cost" of moving each element to find the cheapest operation
3. Uses simultaneous rotations (`rr`, `rrr`) when possible to optimize moves
4. Pushes elements back from B to A in sorted order

## Instructions

### Prerequisites

- GCC compiler
- Make
- A Unix-based system (Linux/macOS)

### Compilation

```bash
make
```

This will compile the `push_swap` executable.

### Execution

```bash
# With multiple arguments
./push_swap 4 67 3 87 23

# With a single string argument
./push_swap "4 67 3 87 23"
```

### Testing

```bash
# Check if the output correctly sorts the stack
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG

# Count the number of operations for 100 random numbers
ARG=$(shuf -i 1-1000 -n 100 | tr '\n' ' '); ./push_swap $ARG | wc -l

# Count the number of operations for 500 random numbers
ARG=$(shuf -i 1-5000 -n 500 | tr '\n' ' '); ./push_swap $ARG | wc -l
```

### Visualizer

You can use external visualizers to see how the algorithm works:

- [push_swap_visualizer](https://github.com/o-reo/push_swap_visualizer) - Clone and build to visualize the sorting process

```bash
# Example with external visualizer
ARG="4 67 3 87 23"; ./push_swap $ARG | ./visualizer
```

## Project Structure

```
├── main.c           # Entry point, input parsing and validation
├── push_swap.h      # Header file with structs and prototypes
├── stack_utils.c    # Stack operations (new_node, add_back, etc.)
├── stack_utils2.c   # Additional stack helpers
├── sort_utils.c     # Sorting utilities (sort_three, fill_stack)
├── swap.c           # sa, sb, ss operations
├── push.c           # pa, pb operations
├── rotate.c         # ra, rb, rr operations
├── reverse_rotate.c # rra, rrb, rrr operations
├── turk_algo.c      # Turk algorithm - target nodes and cost
├── turk_algo2.c     # Turk algorithm - sorting logic
├── libft_utils.c    # ft_isdigit, ft_atoi
├── libft_utils2.c   # ft_split and helpers
└── Makefile         # Build configuration
```

## Resources

### Documentation & References

- [Push_Swap Subject PDF](https://github.com/Binary-Hackers/42_Subjects/blob/master/00_Projects/02_Algorithmic/push_swap.pdf) - Official 42 project subject
- [Turk Algorithm Explanation](https://medium.com/@ayogun/push-swap-c1f5d2d41e97) - Detailed breakdown of the algorithm used
- [Sorting Algorithm Visualizations](https://visualgo.net/en/sorting) - Understanding sorting concepts

### AI Usage

AI assistance (GitHub Copilot) was used in this project for:
- **Code formatting**: Fixing norminette compliance issues (spacing, indentation, line length)
- **File organization**: Splitting functions across multiple files to meet the 5-function-per-file limit
- **Documentation**: Generating this README file
- **Git workflow**: Creating descriptive commit messages

The core algorithm logic and implementation were developed independently.