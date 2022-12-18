#!/bin/bash

echo -e "\nTest 1: sub 1 and 2"
./monty a0.m

echo -e "\nTest 2: normal sub 721"
./monty a1.m

echo -e "\nTest 3: sub with stack too short"
./monty a2.m

echo -e "\nTest 4: sub with empty stack"
./monty a3.m

echo -e "\nTest 5: div with empty stack"
./monty a4.m

echo -e "\nTest 6: div with stack too short"
./monty a5.m

echo -e "\nTest 7: regular division (824)"
./monty a6.m

echo -e "\nTest 8: regular division (824)"
./monty a7.m

echo -e "\nTest 9: can't mul stack too short"
./monty a8.m

echo -e "\nTest 10: can't mul stack empty"
./monty a9.m

echo -e "\nTest 11: regular mult (73-21)"
./monty a10.m

echo -e "\nTest 12: can't mod stack too short"
./monty a11.m

echo -e "\nTest 13: can't mod stack empty"
./monty a12.m

echo -e "\nTest 14: regular mod (4-15-3)"
./monty a13.m








