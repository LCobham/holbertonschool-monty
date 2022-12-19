#include "monty.h"

/**
 * insertQueueNode - insert node when in queue mode
 * @stack: pointer to top of the stack
 * @value: value to be inserted
 *
 * Return: 0 on success
 */
int insertQueueNode(stack_t **stack, int value)
{
	stack_t *newNode = NULL, *tmp;

	if (!stack)
	{
		fprintf(stderr, "Error: stack arg is NULL\n");
		free(global.getlineBuffer);
		fclose(global.filePtr);
		exit(EXIT_FAILURE);
	}

	newNode = malloc(sizeof(stack_t));
	if (!newNode)
	{
		fprintf(stderr, "Error: malloc failed\n");
		freeStack(*stack);
		free(global.getlineBuffer);
		fclose(global.filePtr);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	if (tmp)
	{
		while (tmp->prev)
			tmp = tmp->prev;
	}
	newNode->n = value;
	newNode->next = tmp;
	newNode->prev = NULL;
	if (tmp)
		tmp->prev = newNode;
	else
		*stack = newNode;
	return (0);
}
