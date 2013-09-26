#EECS 281 - Project 1
##Back to the Ship

Run:
g++ p1.cpp
./a.out --queue < tests/testM_nesw.txt
./a.out --stack < tests/testM.txt > testOut.txt

dos2unix -U *; tar czf ./submit.tar.gz *.cpp *.h Makefile test*.txt

reread spec about elevator
so, if I pop off an elevator I CAN look around, yes? Or...what?

more test cases!

moving elevator

// #include <fstream>
// #include <cassert>
// #include <iomanip>