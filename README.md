# k-Dimensional Tree Project for Algorithmics Course at FIB-UPC

## Overview
This project is part of the Algorithmics course at the Facultat d'Informàtica de Barcelona (FIB) of the Universitat Politècnica de Catalunya (UPC). It focuses on implementing various k-dimensional tree data structures (k-d trees) and an algorithm for nearest neighbor searches within these trees. The objective is to experimentally study the average-case performance of the nearest neighbor search algorithm and to report the findings.
<p align="center">
  <img src="https://github.com/PauMayench/PauMayench-k-dimensional_tree_nearest_neighbour/assets/120923489/fb37727e-c2ad-4836-bb0a-ffca1f9a2e6f" alt="image">
</p>


## Implementation
The project implements three variants of k-d trees:
- Standard k-d tree
- Relaxed k-d tree
- Squarish k-d tree

Each tree variant is implemented as separate modules, complemented by a main application to execute nearest neighbor searches and to record performance metrics.

## Requirements
- C++ Compiler (e.g., g++)
- Python 3 (for plotting results)

## Compilation Instructions
Use the provided Makefile to compile the main application and its parallel version with the following commands:

- Compile all necessary objects and the main applications:


```bash
make all
```


- Clean the directory of compiled files:
```bash
make clean
```

## Execution Instructions
Post-compilation, you can perform tests and generate performance data with these commands:

- Execute the standard test and output the timing to `temps.out`:
```bash
make executar_test
```
- Execute parallel tests for different dimensions and output timings to respective files in the `out` directory:
```bash
make executar_tests_par
```
- Generate plots based on the performance data:
```bash
make fer_plots
````
- Generate dimension-based plots:
```bash
make fer_plots2
```

## Project Structure
- `*.cpp` and `*.hh`: Source and header files for the k-d tree variants in C++.
- `plotScript.py` and `plotDimensions.py`: Python scripts for generating performance plots.
- `Makefile`: Makefile for automating compilation and testing processes.

