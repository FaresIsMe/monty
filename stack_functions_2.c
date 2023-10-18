#include "monty.h"

/**
 * add -  adds the top two elements of the stack.
 * @head: points to the address of the stack's last node added
 * @line: The line number
 *
 * Return: nothing
*/
void add(stack_t **head, unsigned int line)
{
	stack_t *temp = NULL;

	if ((*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't", line);
		exit(EXIT_FAILURE);
	}
	temp = (*head)->next;
	temp->n = temp->n + (*head)->n;
	pop(head, line);
	*head = temp;
}
