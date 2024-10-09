# Vector Multiplication

## Overview
A C program that uses linked lists to represent vectors and perform element-wise multiplication, even when vectors have different lengths.

## Features
- **Create Vector**: Reads user input to build a vector as a linked list.
- **Multiply Vectors**: Multiplies elements of two vectors. If one vector is longer, remaining elements are multiplied by zero.
- **Print Vector**: Displays the vector in a readable format.

## Usage
1. Compile: `gcc -o vector_multiplication vector_multiplication.c`
2. Run: `./vector_multiplication`

## Example 
Vector a: 2 -> 4 -> 6 -> NULL Vector b: 3 -> 5 -> NULL Result: 6 -> 20 -> 0 -> NULL
