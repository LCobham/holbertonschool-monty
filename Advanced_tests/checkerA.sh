#!/bin/bash

echo -e "\nTest 1: sub 1 and 2"
./monty a0.m

echo -e "\nTest 2: normal sub 721"
./monty a1.m

echo -e "\nTest 3: sub with stack too short"
./monty a2.m

echo -e "\nTest 4: sub with empty stack"
./monty a3.m


