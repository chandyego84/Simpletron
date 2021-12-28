#pragma once

#include "Header.h"

/*
Variables:
accumulator - accumulator register
instructionCounter - tracks location in memory that contains instruction being performed
operationCode - operation currently being performed (left two digits of instruction)
operand - memory location on which current instruction operates (rightmost two digits of instruction)
instructionRegister - next instruction to be performed from memory

-Do not execute instructions directly from memory
-Transfer the next instruction to be performed from memory to variable called instructionRegister
-Then, "pick off" the left two digits and place them in operationCode, 
-"pick off" the right two digits and place them in operand

Halt instruction:
-Displays termination message
-Causes SIMP to display the name and contents of each register
-Also displays the complete contents of memory
-^Printout is referred to as "register and memory dump"^

Example of register and memory dump:

REGISTERS:
accumulator +0000
instructionCounter 00
instructionRegister +0000
operationCode 00
operand 00

MEMORY:
	   0	 1	   2     3     4     5     6     7     8     9
 0 +0000 +0000 +0000 +0000 +0000 +0000 +0000 +0000 +0000 +0000
10 +0000 +0000 +0000 +0000 +0000 +0000 +0000 +0000 +0000 +0000
20 +0000 +0000 +0000 +0000 +0000 +0000 +0000 +0000 +0000 +0000
30 +0000 +0000 +0000 +0000 +0000 +0000 +0000 +0000 +0000 +0000
40 +0000 +0000 +0000 +0000 +0000 +0000 +0000 +0000 +0000 +0000
50 +0000 +0000 +0000 +0000 +0000 +0000 +0000 +0000 +0000 +0000
60 +0000 +0000 +0000 +0000 +0000 +0000 +0000 +0000 +0000 +0000
70 +0000 +0000 +0000 +0000 +0000 +0000 +0000 +0000 +0000 +0000
80 +0000 +0000 +0000 +0000 +0000 +0000 +0000 +0000 +0000 +0000
90 +0000 +0000 +0000 +0000 +0000 +0000 +0000 +0000 +0000 +0000
*/

class Simp {
public:
	Simp();
	void displayStart();

	const int* getMemory() const;
	const int& getCurrRegister() const;

	void promptUser(int& memloc, int& currRegister);

	void dataDump();
	void runSystem();

private:
	int memory[100];
	int accumulator;
	int instructionCounter;
	int operationCode;
	int operand;
	int instructionRegister;
};