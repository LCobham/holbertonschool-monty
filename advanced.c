#include "monty.h"

/**
 * subF - subtract top two elements from stack
 * @stack: pointer to top of stack
 * @line_number: line n
 *
 * Return: void
 */
void subF(stack_t **stack, unsigned int line_number)
{
	int aux;
	stack_t *tmp;

	if (!stack)
	{
		fprintf(stderr, "Argument passed as stack is NULL\n");
		free(global.getlineBuffer);
		fclose(global.filePtr);
		exit(EXIT_FAILURE);
	}
	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		if (*stack)
			freeStack(*stack);
		free(global.getlineBuffer);
		fclose(global.filePtr);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	aux = tmp->n;
	tmp->prev->n -= aux;
	*stack = tmp->prev;
	tmp->prev->next = NULL;
	free(tmp);
}
