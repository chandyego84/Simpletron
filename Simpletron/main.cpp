#include "SML.h"

/*dynamically allocates/reallocates memory depending on size of
PARAM: user string input*/
char* dyn_strIn();

int main(int argc, char** argv) {

    char* dyStr = dynamicCharString();
    cout << dyStr << endl;

	/*Simp SML;

	SML.runSystem();*/

	return 0;
}

char* dyn_strin() {
    char* line = NULL, * tmp = NULL;
    size_t size = 0, index = 0;
    int ch = EOF;

    while (ch) {
        ch = getc(stdin);

        if (ch == EOF || ch == '\n')
            // stop getting from input
            ch = 0;

        if (size <= index) {
            // check if need to expand
            size += BLOCK_SIZE;
            tmp = (char*)realloc(line, size);
            if (!tmp) {
                free(line);
                line = NULL;
                break;
            }
            line = tmp;
        }
        line[index++] = ch;
    }

    return line;
}