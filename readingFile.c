#include "monty.h"
/**
 * readingTheFile - A function to read the file
 * @myFile: A pointer to the file that is being read
 * @myStack: A double pointer to my stack
 *
 * Return: The status of the function
*/

int readingTheFile(FILE *myFile, stack_t **myStack)
{
	char *myLine = NULL;
	size_t lineLength = 0;
	int readStatus;
	unsigned int lineCount = 1;

	while ((readStatus = getline(&myLine, &lineLength, myFile)) != -1)
	{
		readingTheCommand(myLine, lineLength, lineCount, myStack);
		lineCount++;
	}
	free(myLine);
	return (EXIT_SUCCESS);
}

/**
 * readingTheCommand - A function to tokenize the command
 * parameters
 * @myLine: The command line
 * @lineLength: The length of the line
 * @myLineN: The number of the line
 * @myStack: A double pointer to the stack
 *
 * Return: Nothing (void)
*/

void readingTheCommand(char *myLine, size_t lineLength,
unsigned int myLineN, stack_t **myStack)
{
	char *myCommandCode, *value;
	(void)lineLength;
	myCommandCode = strtok(myLine, "\n ");
	if (myCommandCode == NULL)
		return;
	value = strtok(NULL, "\n ");
	callingTheFunction(myCommandCode, value, myLineN, myStack);
}

/**
 * findingMyFunction - Finds and returns the
 * appropriate function based on the given instruction.
 * @myFO: The instruction to be searched.
 * @myValue: The value associated with the instruction (for push).
 * @myLine: The line number of the instruction.
 * @myStack: A pointer to the stack.
 *
 * Return: A function pointer to the corresponding instruction function.
 * If the instruction is "push", it performs the push
 * operation and returns NULL.
 * If the instruction is found in the
 * instruction list, it returns the corresponding function.
 * Otherwise, it prints an error message and exits the program.
 */

void (*findingMyFunction(char *myFO, char *myValue, unsigned int myLine, stack_t **myStack))(stack_t **, unsigned int)
{
	int i;
	instruction_t myInstruction[] = {
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", division},
		{"mul", multiplication},
		{"swap", swap},
		{"mod", mod},
		{"pchar", puttingChar},
		{"pstr", puttingString},
		{"rotl", rotl},
		/*
		{"rotr", rotr},
		*/
		{NULL, NULL}
		};

	if (myFO[0] == '#')
		return (NULL);
	if (_strcmp(myFO, "push") == 0)
	{
		push(myStack, myLine, myValue);
		return (NULL);
	}
	for (i = 0; myInstruction[i].opcode != NULL; i++)
	{
		if (_strcmp(myInstruction[i].opcode, myFO) == 0)
			return (myInstruction[i].f);
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", myLine, myFO);
	exit(EXIT_FAILURE);
}

/**
 * callingTheFunction - A function to calls findingMyFunction
 * function, in other words it gets the pointer and execute the function
 * @myCommand: The command line
 * @value: The value for push function
 * @myLineN: The number of the line
 * @myStack: A double pointer to the stack
 *
 * Return: Nothing (void)
*/

void callingTheFunction(char *myCommand, char *value,
unsigned int myLineN, stack_t **myStack)
{
	void (*myFunction)(stack_t **, unsigned int) = findingMyFunction
	(myCommand, value, myLineN, myStack);

	if (myFunction != NULL)
		myFunction(myStack, myLineN);
	else
		return;
}
