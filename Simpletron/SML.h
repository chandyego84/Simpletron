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
--------------------------------------------------------------
ERROR CHECKING
--------------------------------------------------------------
[x] Program loading phase: 
	* each 'word', x, -9999 < x < +9999
[x] Execution Phase: 
	-FATAL ERRORS-
	* divide by zero 
	* invalid operation codes
	* accumulator overflows (arithmetic ops. > +9999 or < -9999)
	^^ Errors known as fatal errors

Detecting an error:
	- When fatal error is detected, display the corresponding error message.
	- Abort execution.
	- Display full register and memory dump to help user locate error in the program.
*/

/*size of memory*/
#define MAX_MEMORY 100

/*operation codes*/
#define READ 10
#define WRITE 11
#define LOAD 20
#define STORE 21
#define ADD 30
#define SUBTRACT 31
#define DIVIDE 32
#define MULTIPLY 33
#define BRANCH 40
#define BRANCHNEG 41
#define BRANCHZERO 42
#define HALT 43

class Simp {
public:
	Simp();
	void displayStart();

	void promptUser(int &counter, int &input);
	void executeProgram();
	void errorCheck();

	void dataDump();
	void runSystem();

private:
	int memory[MAX_MEMORY];
	int accumulator;
	int instructionCounter;
	int operationCode;
	int operand;
	int instructionRegister;
};