#include "SML.h"

Simp::Simp() {
	accumulator = 0;
	instructionCounter = 0;
	operationCode = 0;
	operand = 0;
	instructionRegister = 0;
	debugMode = false;
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
			case EMPTY:
				break;
			
			case HALT:
				debugMode = false; // redundant memory dump if true
				break;

			case SML_DEBUG:
				if (operand == 01) {
					debugMode = true;
				}
				else if (operand == 00) {
					debugMode = false;
				}
				break;

			case READ:
				cout << "*Reading to memory location " << operand << "*" << endl;
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
				if (memory[operand] == 0) {
					throw "Divide by Zero Error";
				}
				accumulator /= memory[operand];
				break;

			case MULTIPLY:
				accumulator *= memory[operand];
				break;

			case MODULO:
				accumulator %= memory[operand];
				break;

			case EXPONENT:
				accumulator = pow(float(accumulator), float(memory[operand]));

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

			case NEWLINE:
				cout << endl;
				break;

			case STRING_IN:
				// handling string input
				// stores each string beginning @ specified mem location
				{
					string strIn;
					int loc = operand;
					cout << "Input string: ";
					cin >> strIn;

					size_t strSize = strIn.length();
					memory[loc - 1] = strSize; // store size of string
					int i = 0;
					for (loc; loc < strSize + operand; loc++) {
						memory[loc] = (int)strIn[i];
						i++;
					}
				}
				break;

			case STRING_OUT:
				// handles outputting string starting from specific mem location
				{
					int loc = operand;
					int strSize = memory[loc - 1];
					
					cout << "Output string: ";
					for (int i = loc; i < strSize + loc; i++) {
						cout << (char)memory[i];
					}
					cout << endl;
				}
				break;

			default:
				// not a valid operation code
				throw "Invalid Operation Code found";
			}
		if (debugMode) {
			dataDump();
		}
		if (accumulator < -9999) {
			throw "Accumulator Underflow";
		}
		else if (accumulator > 9999) {
			throw "Accumulator Overflow";
		}

		instructionCounter++;
		}

	cout << "*** Program execution completed ***" << endl << endl;
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

	for (int n = 0; n < 10; n++) {
		// displays x column
		cout << "     " << n;    //n is the element to print !
	}
	cout << endl;

	int j = 0;
	for (int i = 0; i < MAX_MEMORY / 10; i++) {
		// displays y-column
		cout << noshowpos << setw(2) << setfill(' ') << internal << 10 * i;
		cout << " ";
		for (j; j < (MAX_MEMORY / (MAX_MEMORY / 10) + (10 * (i))); j++) {
			// displays each memory element
			cout << showpos << setw(5) << setfill ('0') << internal << memory[j];
			cout << " ";
		}
		cout << endl;
	}
	cout << endl;
}

/*runs SML*/
void Simp::runSystem() {
	int numInstructions = 0;
	int input = 0;

	displayStart();

	while (input != -9999) {
		promptUser(numInstructions, input);	
	}

	cout << endl << "*** Program loading completed ***" << endl;
	cout << "*** Program execution begins ***" << endl << endl;
	// execute program once user finishes inputting
	try {
		executeProgram();
	}
	catch (const char* errMsg) {
		cout << "*** Program abnormally terminated ***" << endl;
		cout << "*** " << errMsg << " ***" << endl << endl;
	}
	// dump all data after execution completes
	dataDump();
}

/*WILL USE <STRING> INSTEAD*/
char* dyn_strIn() {
	char* line = nullptr, * tmp = nullptr;
	size_t size = 0, index = 0;
	char ch = NULL;

	do {
		ch = getc(stdin);
		if (ch == '\n') {
			ch = '\0';
		}

		if (size <= index) {
			// check if need to expand
			size += BLOCK_SIZE;
			tmp = (char*)realloc(line, size * 2); // assign line to temp in case line returns nullptr
			if (!tmp) {
				free(line);
				line = NULL;
				break;
			}
			line = tmp;
		}
		line[index++] = ch;

	} while (ch != '\0');

	return line;
}