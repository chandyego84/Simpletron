#include "SML.h"

Simp::Simp() {
	// initialize every element in memory to 0
	for (int i = 0; i < MAX_MEMORY; i++) {
		memory[i] = 0;	
	}

	accumulator = 0;
	instructionCounter = 0;
	operationCode = 0;
	operand = 0;
	instructionRegister = 0;
}

void Simp::displayStart() {
	cout << "*** Welcome to Simpletron! ***" << endl << endl;
	cout << "*** Please enter your program one instruction ***" << endl;
	cout << "*** (or data word) at a time.I will type the ***" << endl;
	cout << "*** location numberand a question mark(?). ***" << endl;
	cout << "*** You then type the word for that location. ***" << endl;
	cout << "*** Type the sentinel -99999 to stop entering ***" << endl;
	cout << "*** your program. ***" << endl;
}

/*returns x-word memory array*/
const int* Simp::getMemory() const{
	return memory;
} 

/*gets next instruction to be executed from the register*/
const int& Simp::getCurrRegister() const {
	return instructionRegister;
}

/*prompts user for "word" to be placed and loads into memory*/
/*counter: tracks current instruction location*/
void Simp::promptUser(int &counter, int &input) {
	cout << counter << " ? ";
	cin >> input;
	if (input != -9999) {
		// user keeps entering instructions
		memory[counter] = input;
		counter++;
	}
}

/*executes instructions loaded into memory*/
void Simp::executeProgram() {
	while (instructionCounter < MAX_MEMORY && memory[instructionCounter] != HALT) {
		// sets instruction variables
		instructionRegister = memory[instructionCounter];
		operationCode = instructionRegister / 100;
		operand = instructionRegister % 100;

		switch (operationCode) {
		case READ: 
			cin >> memory[operand];
			break;

		case WRITE:
			cout << memory[operand] << endl;
			break;

		case LOAD:
			accumulator = memory[operand];
			break;

		case STORE:
			memory[operand] = accumulator;
			break;

		case ADD:
			accumulator += memory[operand];
			break;

		case SUBTRACT:
			accumulator -= memory[operand];
			break;

		case DIVIDE:
			accumulator /= memory[operand];
			break;

		case MULTIPLY:
			accumulator *= memory[operand];
			break;

		case BRANCH:
			instructionCounter = operand - 1;
			break;

		case BRANCHNEG:
			if (accumulator < 0) {
				instructionCounter = operand - 1;
			}
			break;

		case BRANCHZERO:
			if (accumulator == 0) {
				instructionCounter = operand - 1;
			}
			break;

		default: 00;
		}
		instructionCounter++;
	}
	cout << "*** Program execution completed ***" << endl;
}

/*after program finishes: displays memory and registers*/
void Simp::dataDump() {
	cout << "Memory Dump: " << endl;
	for (int i = 0; i < MAX_MEMORY; i++) {
		cout << i << " " << memory[i] << endl;
	}
}

/*runs SML*/
void Simp::runSystem() {
	int numInstructions = 0;
	int input = 0;

	displayStart();

	while (input != -9999) {
		promptUser(numInstructions, input);
	}
	cout << "*** Program loading completed ***" << endl;
	cout << "*** Program execution begins ***" << endl;
	// execute program once user finishes inputting
	executeProgram();

	dataDump();
}