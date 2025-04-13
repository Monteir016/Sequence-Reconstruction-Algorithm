# Sequence-Reconstruction-Algorithm

## Overview

This project implements a solution for reconstructing sequences based on a given set of rules and operations. The program reads input data, processes it using a dynamic programming approach, and outputs whether the desired result can be achieved along with the reconstructed sequence.

## Features

- Reads input data including a matrix of operations, a sequence, and a target result.
- Uses a dynamic programming table to compute possible results for sub-sequences.
- Reconstructs and outputs the sequence that leads to the target result if it exists.
- Handles edge cases such as single-element sequences or sequences that cannot produce the target result.

## Input Format

The program expects the following input format:

1. An integer `setSize` representing the size of the set (e.g., 3 for `{1, 2, 3}`).
2. An integer `sequenceSize` representing the size of the sequence.
3. A `setSize x setSize` matrix of integers representing the operation results.
4. A sequence of integers of size `sequenceSize`.
5. An integer `result` representing the target result.

### Example Input
3 4 1 2 3 4 5 6 7 8 9 2 1 3 2 5

## Output Format

The program outputs:

1. `1` if the target result can be achieved, followed by the reconstructed sequence in parentheses.
2. `0` if the target result cannot be achieved.

### Example Output
1 (2 (1 (3 2)))

## How It Works

1. **Dynamic Programming Table**: The program uses a 3D table (`result_matrix`) to store possible results for sub-sequences.
2. **Recursive Reconstruction**: If the1 early if the target result is found during computation.

## File Structure

- `Project1.c++`: The main source code file containing all logic for input reading, processing, and output generation.

## How to Build

To compile the project, use the provided `Makefile`. Run the following commands:

`g++ -std=c++17 -o Project1 [Project1.c++]`

##Dependencies
C++17 or later
Standard libraries: <iostream>, <vector>, <algorithm>, <unordered_set>

Author
Developed by Guilherme Monteiro. For more information, visit [GitHub profile](https://github.com/Monteir016).
