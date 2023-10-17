#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

/**
 * struct list_t - doubly linked list of a stack
 * @n: an integer data
 * @next: points to the next node in the list or the stack
 * @prev: points to the previous nodein the list or the stack
 * 
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 * 
*/
typedef struct list_t
{
    int n;
    struct stack *next;
    struct stack *prev;
} stack;


#endif /*MONTY_H*/