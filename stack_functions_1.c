#include "monty.h"


/**
 * push - A function to add a node at the beginning
 * @head: A pointer to a pointer that points to the head
 * @line: The line number
 * @arg: arguments
 *
 * Return: nothing
*/

void push(stack_t **head, unsigned int line, char *arg)
{
	stack_t *node = NULL;
	int len = 0, i;

	len = strlen(arg);
	for (i = 0; i < len; i++)
	{
		if (arg[i] > 57 && arg[i] < 48)
		{
			fprintf(stderr, "L%d: usage: push integer", line);
			exit(EXIT_FAILURE);
		}
	}

	node = add_dnodeint(head, atoi(arg));

	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	(*head) = node;
}

/**
 * pall - prints all the values on the stack, starting from the top of
 * the stack
 * @head: points to the address of the stack's last node added
 * @line: The line number
 *
 * Return: nothing
*/
void pall(stack_t **head, unsigned int line)
{
	stack_t *temp = *head;
	(void)line;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
  * pint -  prints the value at the top of the stack
  * @head: points to the stacks first node
  * @line: The line number
  *
  * Return: nothing
 */
void pint(stack_t **head, unsigned int line)
{
	stack_t *temp  = *head;

	if (!head || !*head)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}

	while (temp)
	{
		if (temp->prev == NULL)
			break;
		temp = temp->prev;
	}
	printf("%d\n", temp->n);
}

/**
 * pop - removes the top element of the stack.
 * @head: A pointer to a pointer that points to the head
 * @line: The line number
 *
 * Return: nothing
*/

void pop(stack_t **head, unsigned int line)
{
	(void)line;

	if (*head || head)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
		exit(EXIT_FAILURE);
	}

	if ((*head)->next != NULL)
	{
		*head = (*head)->next;
		free((*head)->prev);
		(*head)->prev = NULL;
	}
	else
	{
		free(*head);
		*head = NULL;
	}
}

/**
 * nop - doesn't do anything
 * @head: A pointer to a pointer that points to the head
 * @line: The line count
 *
 * Return: Nothing
*/
void nop(stack_t **head, unsigned int line)
{
	(void)head;
	(void)line;
}
