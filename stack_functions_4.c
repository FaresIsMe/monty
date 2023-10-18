#include "monty.h"

/**
 * puttingChar - prints the last char in the stack.
 * @head: A pointer to a pointer that points to the head
 * @line: The line number
 *
 * Return: nothing
*/

void puttingChar(stack_t **head, unsigned int line)
{
	int myVar;

	(void)line;
	if (!*head || !head)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	myVar = (*head)->n;
	/*A- 65 --- Z- 90  ---- a- 97 ---- z- 122*/
	if ((myVar >= 65 && myVar <= 90) || (myVar >= 97 && myVar <= 122))
		printf("%c\n", myVar);
	else
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line);
		exit(EXIT_FAILURE);
	}
}
