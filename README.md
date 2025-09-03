# ADA Project: Dynamic Programming Toolkit

## Overview

This repository contains an interactive C-based toolkit for solving classic Dynamic Programming (DP) problems. It features a user-friendly interface with an interactive menu system, comprehensive input validation, and detailed explanations for each algorithm. The toolkit demonstrates the power of memoization to optimize recursive solutions, providing efficient ways to tackle problems like the Fibonacci sequence, the 0/1 Knapsack problem, and Coin Change.

The toolkit is designed with modularity and user experience in mind, allowing for easy extension to include other dynamic programming challenges. It features a generic `DPProblem` structure that can wrap various specific DP problem instances and their respective solvers, offering a unified interface for computation.

## Features

### Core Algorithms
* **Fibonacci Sequence Solver:** Efficiently calculates the Nth Fibonacci number using top-down dynamic programming (memoization).
* **0/1 Knapsack Problem Solver:** Determines the maximum value that can be obtained by selecting items within a given weight capacity, utilizing memoization to optimize the solution.
* **Coin Change Problem Solver:** Finds the minimum number of coins needed to make a specific amount using dynamic programming.

### User Interface & Experience
* **Interactive Menu System:** Clean, intuitive menu-driven interface for easy navigation
* **User Input Validation:** Comprehensive error checking and validation for all inputs
* **Detailed Results Display:** Enhanced output formatting with explanatory information
* **Algorithm Information:** Built-in help system explaining time/space complexity and usage
* **Error Handling:** Robust error messages and graceful handling of edge cases

### Technical Features
* **Generic `DPProblem` Wrapper:** A flexible structure (`DPProblem`) that allows you to abstractly define and solve any dynamic programming problem by encapsulating its specific data and solver function.
* **Memory Management:** Includes functions for proper allocation and deallocation of memory for problem instances.
* **Performance Warnings:** Alerts users when working with potentially time-consuming computations.

## Project Structure

The project is organized into a `dp_toolkit` directory containing the core source files:

```
dp_toolkit/
├── dptoolkit.h      # Header file with structure definitions and function declarations
├── dptoolkit.c      # Core implementation of DP algorithms and data structures
└── main.c           # Interactive user interface and menu system
```

## Building and Running

To compile and run the toolkit:

```bash
cd dp_toolkit
gcc -o dptoolkit main.c dptoolkit.c
./dptoolkit
```

## Usage Examples

### Fibonacci Sequence
- Enter position n (e.g., 10)
- Displays F(10) = 55 with the sequence: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55

### 0/1 Knapsack Problem
- Input: 4 items, capacity 7
- Items: weights [1,3,4,5], values [1,4,5,7]
- Output: Maximum value = 9

### Coin Change Problem
- Input: coins [1,5,10], target amount 11
- Output: Minimum coins needed = 2 (one 10-coin + one 1-coin)

## Algorithm Complexities

| Algorithm | Time Complexity | Space Complexity |
|-----------|----------------|------------------|
| Fibonacci | O(n) | O(n) |
| 0/1 Knapsack | O(n × capacity) | O(n × capacity) |
| Coin Change | O(amount × coins) | O(amount) |

## Features Added in v2.0

- ✅ **Interactive Menu System** - User-friendly navigation
- ✅ **Input Validation** - Comprehensive error checking
- ✅ **Enhanced Output** - Better formatted results with explanations
- ✅ **Algorithm Information** - Built-in help system
- ✅ **Coin Change Problem** - Additional DP algorithm
- ✅ **Error Handling** - Graceful handling of edge cases
- ✅ **Performance Warnings** - Alerts for large computations
