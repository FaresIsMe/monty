#include "monty.h"

/**
 * mod - computes the rest of the division of the second top
 * element of the stack by the top element of the stack.
 *
 * @head: points to the address of the stack's last node added
 * @line: The line number
 *
 * Return: nothing
*/

void mod(stack_t **head, unsigned int line)
{
	stack_t *temp = NULL;

	if (!*head || !(*head)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line);
		exit(EXIT_FAILURE);
	}
	temp = (*head)->next;
	temp->n = temp->n % temp->prev->n;
	pop(head, line);
}


/**
 * swap - swaps the top two elements of the stack.
 * @head: points to the address of the stack's last node added
 * @line: The line number
 *
 * Return: nothing
*/

void swap(stack_t **head, unsigned int line)
{
	stack_t *temp = NULL;
	int hold;

	if (!*head || !(*head)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line);
		exit(EXIT_FAILURE);
	}

	hold = (*head)->n;
	temp = (*head)->next;
	(*head)->n = temp->n;
	temp->n = hold;
}

/**
 * rotl - rotates the stack to the top.
 * @head: points to the address of the stack's last node added
 * @line: The line number
 *
 * Return: nothin
*/
void rotl(stack_t **head, unsigned int line)
{
	stack_t *last = *head;

	if (*head == NULL || (*head)->next == NULL)
		return;

	while (last->next != NULL)
		last = last->next;

	last->next = *head;
	(*head)->prev = last;
	*head = (*head)->next;
	(*head)->prev->next = NULL;
	(*head)->prev = NULL;

	(void)line;
}
