#include "SML.h"

Simp::Simp() {
	// initialize every element in memory to 0
	for (int i = 0; i < 100; i++) {
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

/*prompts user for "word" to be placed into memory and instruction register*/
void Simp::promptUser(int& memloc, int& currRegister) {
	cout << memloc << " ? ";
	cin >> memory[memloc];
	instructionRegister = memory[memloc];
	memloc++;
}

/*after program finishes: displays memory and registers*/
void Simp::dataDump() {
	cout << "Memory Dump: " << endl;
	for (int i = 0; i < 100; i++) {
		cout << i << " " << memory[i] << endl;
	}
}

/*runs SML*/
void Simp::runSystem() {
	displayStart();

	while (getCurrRegister() != -9999) {
		promptUser(instructionCounter, instructionRegister);
	}

	dataDump();
}