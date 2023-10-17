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


/**
 *add_nodeint_end - adds a new node at the beginning of a stack_t list.
 * @head: Head of the list pointer.
 * @n: int to set in the new node.
 * Return: address of the new element, or NULL if it failed
*/

stack_t *add_nodeint_end(stack_t **head, const int n)
{
	stack_t *new_end, *temp = *head;

	new_end = malloc(sizeof(stack_t));
	if (new_end == NULL)
		return (NULL);

	new_end->n = n;
	new_end->next = NULL;

	if (temp)
	{
		while (temp->next)
			temp = temp->next;
		new_end->prev = temp;
		temp->next = new_end;
	}
	else
	{
		*head = new_end;
		new_end->prev = NULL;
	}
	return (*head);
}
