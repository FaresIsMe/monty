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

	if (!(*head)->next || !*head)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
		free_dlistint(*head);
		exit(EXIT_FAILURE);
	}
	temp = (*head)->next;
	temp->n = temp->n + temp->prev->n;
	pop(head, line);
	*head = temp;
	(*head)->prev = NULL;
}

/**
 * sub -  sub the top two elements of the stack.
 * @head: points to the address of the stack's last node added
 * @line: The line number
 *
 * Return: nothing
*/
void sub(stack_t **head, unsigned int line)
{
	stack_t *temp = NULL;

	if (!(*head)->next || !*head)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	temp = (*head)->next;
	temp->n = temp->n - temp->prev->n;
	pop(head, line);
}
