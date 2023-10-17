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

void (*findingMyFunction(char *myFO, char *myValue))(stack_t **, unsigned int)
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

	}
}