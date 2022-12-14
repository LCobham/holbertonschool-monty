#include "monty.h"

/**
 * init - initialize the stack
 *
 * Return: 0 on success
 */

int init(void)
{
	top = NULL;
	return (0);
}

/**
 * pushF - function to push an element to the stack
 * @value: value to push
 *
 * Return: void
 */

void pushF(int value)
{
	stack_t *newNode = NULL;

	newNode = malloc(sizeof(stack_t));
	if (!newNode)
	{
		fprintf(stderr, "Error: malloc failed\n");
		/* Will have to free everything before exit */
		exit (EXIT_FAILURE);
	}
	newNode->n = value;
	newNode->next = NULL;
	newNode->prev = top;
	if (top)
		top->next = newNode;
	top = newNode;
}

/**
 * pallF - print all elements in the stack
