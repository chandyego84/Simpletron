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

/*prompts user for "word" to be placed and loads into memory*/
/*counter: tracks current instruction location*/
void Simp::promptUser(int &counter, int &input) {
	do {
		cout << setw(2) << setfill('0') << internal << counter;
		cout << " ? ";
		cin >> input;
	} while (input < -9999 || input > 9999); // 'word' input must be in range

	if (input != -9999) {
		// user keeps entering instructions
		memory[counter] = input;
		counter++;
	}
}

/*executes instructions loaded into memory*/
void Simp::executeProgram() {
	while (instructionCounter < MAX_MEMORY && operationCode != HALT) {
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
	cout << "*** Program execution completed ***" << endl << endl;
}

/*
[x] Execution Phase:
	* divide by zero
	* invalid operation codes
	* accumulator overflows (arithmetic ops. > +9999 or < -9999)
	^^ Errors known as fatal errors

Detecting an error:
	- When fatal error is detected, display the corresponding error message.
	- Abort execution.
	- Display full register and memory dump to help user locate error in the program.

*/
void Simp::errorCheck() {
	
}

/*after program finishes: displays memory and registers*/
void Simp::dataDump() {
	cout << "*** Register and Memory Dump ***"<< endl;
	cout << "REGISTERS:" << endl;
	cout << "accumulator " << showpos << setw(5) << setfill('0') << internal << accumulator << endl;
	cout << "instructionCounter " << noshowpos << setw(2) << setfill('0') << internal << instructionCounter << endl;
	cout << "instructionRegister " << showpos << setw(5) << setfill('0') << internal << instructionRegister << endl;
	cout << "operationCode " << noshowpos << setw(2) << setfill('0') << internal << operationCode << endl;
	cout << "operand " << "" << setw(2) << setfill('0') << internal << operand << endl << endl;

	for (int n = 0; n < MAX_MEMORY / 10; n++) {
		// displays x column
		cout << "     " << n;    //n is the element to print !
	}
	cout << endl;

	int j = 0;
	for (int i = 0; i < MAX_MEMORY / 10; i++) {
		// displays y-column
		cout << noshowpos << setw(2) << setfill(' ') << internal << 10 * i;
		cout << " ";
		for (j; j < (MAX_MEMORY / 10) + (10 * (i)) ; j++) {
			// displays each memory element
			cout << showpos << setw(5) << setfill ('0') << internal << memory[j];
			cout << " ";
		}
		cout << endl;
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
	cout << "*** Program execution begins ***" << endl << endl;
	// execute program once user finishes inputting
	executeProgram();

	dataDump();
}