#!/bin/bash
echo -e "\nTest 1 (321)"
./monty f1.txt
echo -e "\nTest 2 (invalid instruction)"
./monty f2.txt
echo -e "\nTest Failure (USAGE: ...)"
./monty
echo -e "\nTest Failure to open file"
./monty HoLbErToN
echo -e "\nTest 3 (invalid instruction)"
./monty f3.txt
echo -e "\nTest 4 (invalid int)"
./monty f4.txt
echo -e "\nTest 5 (pint empty)"
./monty f5.txt
echo -e "\nTest 6 (4334 - pint)"
./monty f6.txt
echo -e "\nTest 7 (pop empty)"
./monty f7.txt
echo -e "\nTest 8 (21131 - normal pop)"
./monty f8.txt

echo -e "\nTest X (pop when only one element)"
./monty f17.txt
echo -e "\nTest X + 1 (pop Holberton)"
./monty f18.txt

echo -e "\nTest 9 (2112 swap)"
./monty f9.txt
echo -e "\nTest 10 (swap 1 element)"
./monty f10.txt
echo -e "\nTest 11 (swap 0 elements)"
./monty f11.txt
echo -e "\nTest 12 (normal add: 1+1)"
./monty f12.txt
echo -e "\nTest 13 (add only 1 element)"
./monty f13.txt
echo -e "\nTest 14 (add empty)"
./monty f14.txt
echo -e "\nTest 15 (nop - 01)"
./monty f15.txt
echo -e "\nTest 16 (nop - do nothing)"
./monty f16.txt







