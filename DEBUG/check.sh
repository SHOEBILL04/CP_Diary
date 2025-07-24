#!/bin/bash

# Compile the programs if not compiled
g++ gen.cpp -o gen.out
g++ a.cpp -o a.out
g++ b.cpp -o b.out

# Ensure executables have the right permissions
chmod +x gen.out a.out b.out

# Stress test loop
for ((i = 1; ; ++i)); do
    
    # Generate input file
    ./gen.out $i > input.txt
    
    # Compare outputs of a.out and b.out
    if ! diff -w <(./a.out < input.txt) <(./brute.out < input.txt); then
        echo "Mismatch found on test $i!"
        break
    fi
done

