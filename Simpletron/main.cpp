#include "SML.h"

/*dynamically allocates/reallocates memory depending on size of
PARAM: user string input*/
char* dyn_strIn();

int main(int argc, char** argv) {
    char* dyStr = dyn_strIn();
    cout << dyStr << endl;

	/*Simp SML;

	SML.runSystem();*/

	return 0;
}

char* dyn_strIn() {
    char* line = nullptr, * tmp = nullptr;
    size_t size = 0, index = 0;
    char ch = NULL;

    do {
        ch = getc(stdin);
        //if (ch == EOF || ch == '\n')
        //    // stop getting from input
        //    ch = 0;
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