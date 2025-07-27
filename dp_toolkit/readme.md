# ADA Project: Dynamic Programming Toolkit

## Overview

This repository contains a simple yet effective C-based toolkit for solving classic Dynamic Programming (DP) problems. It demonstrates the power of memoization to optimize recursive solutions, providing efficient ways to tackle problems like the Fibonacci sequence and the 0/1 Knapsack problem.

The toolkit is designed with modularity in mind, allowing for easy extension to include other dynamic programming challenges. It features a generic `DPProblem` structure that can wrap various specific DP problem instances and their respective solvers, offering a unified interface for computation.

## Features

* **Fibonacci Sequence Solver:** Efficiently calculates the Nth Fibonacci number using top-down dynamic programming (memoization).
* **0/1 Knapsack Problem Solver:** Determines the maximum value that can be obtained by selecting items within a given weight capacity, utilizing memoization to optimize the solution.
* **Generic `DPProblem` Wrapper:** A flexible structure (`DPProblem`) that allows you to abstractly define and solve any dynamic programming problem by encapsulating its specific data and solver function.
* **Memory Management:** Includes functions for proper allocation and deallocation of memory for problem instances.
* **Basic Error Handling:** Incorporates checks for memory allocation failures and invalid inputs, providing more robust execution.

## Project Structure

The project is organized into a `dp_toolkit` directory containing the core source files:
