#include "monty.h"

/**
 * main - entry point
 * @argc: Number of parameters that are passed to the file
 * @argv: The parameters that are passed
 * 
 * Return: The exit status
*/

int main(int argc, char **argv)
{
    stack_t *myStack;
    FILE *myFile;
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    if (argv[1] != NULL)
        myFile = fopen(argv[1], "r");
    if (myFile == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s", argv[1]);
        exit(EXIT_FAILURE);
    }
    readingTheFile(myFile, &myStack);
    fclose(myFile);
}