#include "monty.h"

/**
 * print_dlistint - A function to print the elements of
 * a doubly linked list
 * @h: A pointer to the head of the list
 *
 * Return: The number of elements in the list
*/

size_t print_dlistint(const stack_t *h)
{
	size_t counter = 0;

	while (h != NULL)
	{
		counter++;
		printf("%d\n", h->n);
		h = h->next;
	}
	return (counter);
}

/**
 * add_dnodeint - A function to add a node at the beginning
 * @head: A pointer to a pointer that points to the head
 * @n: The number to be put in the node
 *
 * Return: NULL or a pointer to the newly created node
*/

stack_t*add_dnodeint(stack_t **head, const int n)
{
	stack_t *newNode;

	newNode = (stack_t *)malloc(sizeof(stack_t));
	if (newNode == NULL)
		return (NULL);
	newNode->n = n;
	newNode->prev = NULL;
	newNode->next = *head;
	if (*head != NULL)
		(*head)->prev = newNode;
	*head = newNode;
	return (newNode);
}

/**
 * free_dlistint - A function to free a doubly linked list
 * @head: A pointer to the head
 *
 * Return: Nothing (void)
*/

void free_dlistint(stack_t *head)
{
	stack_t *tempHead, *tempHead1;

	tempHead = head;
	while (tempHead != NULL)
	{
		tempHead1 = tempHead->next;
		free(tempHead);
		tempHead = tempHead1;
	}
	head = NULL;
}
