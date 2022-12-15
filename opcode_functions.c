#include "monty.h"

/**
 * pushF - function to push an element to the stack
 * @stack: address of stack
 * @line_number: line number
 *
 * Return: void
 */

void pushF(stack_t **stack, unsigned int line_number)
{
	int value, i;
	char *str;

	str = strtok(NULL, " \t\n");
	if (!str)
	{
		fprintf(stderr, "L<%u>: usage: push integer\n", line_number);
		freeStack(*stack);
		free(global.getlineBuffer);
		fclose(global.filePtr);
		exit(EXIT_FAILURE);
	}
	else
	{
		for (i = 0; str[i]; i++)
		{
			if (str[i] < '0' || str[i] > '9')
			{
				fprintf(stderr, "L<%u>: usage: push integer\n", line_number);
				freeStack(*stack);
				free(global.getlineBuffer);
				fclose(global.filePtr);
				exit(EXIT_FAILURE);
			}
		}
	}
	value = atoi(str);
	insertNode(stack, value);
}

/**
 * insertNode - insert a new node to the stack
 * @stack: stack
 * @value: int to insert
 *
 * Return: 0 on success
 */
int insertNode(stack_t **stack, int value)
{
	stack_t *newNode = NULL;

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
	newNode->n = value;
	newNode->next = NULL;
	newNode->prev = *stack;
	if (*stack)
		(*stack)->next = newNode;
	*stack = newNode;
	return (0);
}

/**
 * freeStack - free all the nodes of the stack
 * @stack: top of the stack
 *
 * Return: 0 on success
 */
int freeStack(stack_t *stack)
{
	if (!stack)
		return (-1);
	if (stack->prev)
	{
		freeStack(stack->prev);
	}
	free(stack);
	return (0);
}


/**
 * pallF - print all elements in the stack
 * @stack: pointer to stack
 * @line_number: line number
 *
 * Return: void
 */
void pallF(stack_t **stack, unsigned int __attribute__ ((unused)) line_number)
{
	stack_t *tmp = NULL;

	if (!stack)
	{
		fprintf(stderr, "Argument passed as stack is NULL\n");
		free(global.getlineBuffer);
		fclose(global.filePtr);
		exit(EXIT_FAILURE);
	}
	for (tmp = *stack; tmp; tmp = tmp->prev)
		printf("%d\n", tmp->n);
}


