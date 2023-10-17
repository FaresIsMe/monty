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
	myCommandCode = strtok(myLine, "\n ");
	if (myCommandCode == NULL)
		return;
	value = strtok(NULL, "\n ");
	callingTheFunction(myCommandCode, value, myLineN, myStack);
}

/**
 * findingMyFunction - A function to find the pointer
 * to the required function
 * @myFO: The commmand line
 * @myValue: The value for push function
 * @myLine: The number of the line
 * @myStack: A double pointer to the stack
 * 
 * Return: A pointer to the required function
*/

void (*findingMyFunction(char *myFO, char *myValue,
unsigned int myLine, stack_t **myStack))
(stack_t **, unsigned int)
{
	int i;
	instruction_t myInstruction[] ={
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		/*
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", div},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		*/
		{NULL, NULL}
	};
	for (i = 0; myInstruction[i].opcode != NULL; i++)
	{
		if (_strcmp(myInstruction[i].opcode, myFO) == 0)
		{
			if (_strcmp(myFO, "push") == 0)
				push(myStack, myLine, myValue);
			return (myInstruction[i].f);
		}
	}
	fprintf("L%d: unknown instruction %s", myLine, myFO);
	exit(EXIT_FAILURE);
}

/**
 * callingTheFunction - A function to calls findingMyFunction
 * function, in other words it gets the pointer and execute the function
 * @myCommand: The command line
 * @myValue: The value for push function
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