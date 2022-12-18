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


/**
 * divF - divide the second top element of the stack by the top
 * @stack: pointer to top of the stack
 * @line_number: line n
 *
 * Return: void
 */
void divF(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		if (*stack)
			freeStack(*stack);
		free(global.getlineBuffer);
		fclose(global.filePtr);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	aux = tmp->n;
	if (!aux)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		freeStack(*stack);
		free(global.getlineBuffer);
		fclose(global.filePtr);
		exit(EXIT_FAILURE);

	}
	tmp->prev->n /= aux;
	*stack = tmp->prev;
	tmp->prev->next = NULL;
	free(tmp);
}


/**
 * mulF - multiply the two top elements in the stack
 * @stack: pointer to top of the stack
 * @line_number: line n
 *
 * Return: void
 */
void mulF(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		if (*stack)
			freeStack(*stack);
		free(global.getlineBuffer);
		fclose(global.filePtr);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	aux = tmp->n;
	tmp->prev->n *= aux;
	*stack = tmp->prev;
	tmp->prev->next = NULL;
	free(tmp);
}


/**
 * modF - compute the remainder of div the second top element by the top
 * @stack: pointer to top of the stack
 * @line_number: line n
 *
 * Return: void
 */
void modF(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		if (*stack)
			freeStack(*stack);
		free(global.getlineBuffer);
		fclose(global.filePtr);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	aux = tmp->n;
	if (!aux)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		freeStack(*stack);
		free(global.getlineBuffer);
		fclose(global.filePtr);
		exit(EXIT_FAILURE);

	}
	tmp->prev->n %= aux;
	*stack = tmp->prev;
	tmp->prev->next = NULL;
	free(tmp);

}
