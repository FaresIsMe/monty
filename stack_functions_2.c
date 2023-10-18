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

	if (!*head || !(*head)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	temp = (*head)->next;
	temp->n = temp->n + temp->prev->n;
	pop(head, line);
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

	if (!*head || !(*head)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	temp = (*head)->next;
	temp->n = temp->n - temp->prev->n;
	pop(head, line);
}

/**
 * sub -  sub the top two elements of the stack.
 * @head: points to the address of the stack's last node added
 * @line: The line number
 *
 * Return: nothing
*/

void division(stack_t **head, unsigned int line)
{
	stack_t *temp = NULL;

	if (!*head || !(*head)->next) 
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line);
		exit(EXIT_FAILURE);
	}
	temp = (*head)->next;
	temp->n = temp->n / temp->prev->n;
	pop(head, line);
}