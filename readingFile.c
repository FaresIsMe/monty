#include "monty.h"

int readingTheFile(FILE *myFile)
{
    char *myLine = NULL;
    size_t lineLength = 0;
    int readStatus;

    while ((readStatus = getline(&myLine, &lineLength, myFile)) != -1)
    {
        readingTheCommand(myLine, lineLength);
    }
    free(myLine);
}

void readingTheCommand(char *myLine, size_t lineLength)
{
    char *myCommandCode, *value;
    myCommandCode = strtok(myLine, "\n ");
    if (myCommandCode == NULL)
        return;
    value = strtok(NULL, "\n ");
    findingMyFunction(myCommandCode, value);
}

void findingMyFunction(char *myFO, char *myValue)
{
    int i;
    instruction_t myInstruction[] ={
        {"push", push}
        {"pall", pall}
        {"pint", pint}
    };
}

//         char *opcode;
//         void (*f)(stack_t **stack, unsigned int line_number);
// } instruction_t;