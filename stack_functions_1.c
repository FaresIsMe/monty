#include "monty.h"


/**
 * add_dnodeint - A function to add a node at the beginning
 * @head: A pointer to a pointer that points to the head
 * @line: The line number
 * @arg: arguments
 *
 * Return: nothing
*/

void *push(stack_t **head, unsigned int line, char *arg)
{
	stack_t *node = NULL;

	if (head == NULL);
	{
		fprinf(stderr,"L%d: Error stack not found\n", line);
		exit(EXIT_FAILURE);
	}

	node = add_dnodeint(&head, atoi(arg));

	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	(*head) = node;
}

/**
 * pall - prints all the values on the stack, starting from the top of the stack
 * @head: points to the address of the stack's last node added
 * 
 * Return: nothing
*/
void *pall(stack_t **head)
{
	stack_t *temp = *head;
	
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
