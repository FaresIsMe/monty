#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/*Linked List Functions*/
size_t print_dlistint(const stack_t *h);
stack_t*add_dnodeint(stack_t **head, const int n);
void free_dlistint(stack_t *head);
stack_t *add_nodeint_end(stack_t **head, const int n);


/*stack_functions_1*/
void push(stack_t **head, unsigned int line, char *arg);
void pall(stack_t **head, unsigned int line);
void pint(stack_t **head, unsigned int line);
void pop(stack_t **head, unsigned int line);
void nop(stack_t **head, unsigned int line);

/*stack_functions_2*/
void add(stack_t **head, unsigned int line);
void sub(stack_t **head, unsigned int line);
void division(stack_t **head, unsigned int line);
void multiplication(stack_t **head, unsigned int line);

/*stack_functions_3*/
void mod(stack_t **head, unsigned int line);
void swap(stack_t **head, unsigned int line)

/*String Functions*/
int _strcmp(char *X, char *Y);

/*Handling The File*/
int readingTheFile(FILE *, stack_t **);
void readingTheCommand(char *, size_t, unsigned int, stack_t **);
void (*findingMyFunction(char *, char *,
unsigned int, stack_t **))(stack_t **, unsigned int);
void callingTheFunction(char *myCommand, char *value,
unsigned int myLineN, stack_t **myStack);

#endif /*MONTY_H*/
