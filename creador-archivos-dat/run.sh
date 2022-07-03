#!/usr/bin/env bash

# Compile
gcc -Wall ./main.c -o main.dat

# Run
./main.dat

# Delete executable
rm -f ./main.dat
