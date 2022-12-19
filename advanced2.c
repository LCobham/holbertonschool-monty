#include "monty.h"

/**
 * pcharF - prints the char at the top of the stack,
 * followed by a new line
 * @stack: pointer to top of the stack
 * @line_number: line n
 *
 * Return: void
 */

void pcharF(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!stack)
	{
		fprintf(stderr, "Argument passed as stack is NULL\n");
		free(global.getlineBuffer);
		fclose(global.filePtr);
		exit(EXIT_FAILURE);
	}
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		free(global.getlineBuffer);
		fclose(global.filePtr);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	if (tmp->n < 0 || tmp->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		free(global.getlineBuffer);
		fclose(global.filePtr);
		exit(EXIT_FAILURE);
	}
	else
		fprintf(stdout, "%c\n", tmp->n);
}


/**
 * pstrF - print the string at the top of the stack
 * @stack: pointer to top of the stack
 * @line_number: line n
 *
 * Return: void
 */
void pstrF(stack_t **stack, unsigned int __attribute__ ((unused)) line_number)
{
	stack_t *tmp;

	if (!stack)
	{
		fprintf(stderr, "Argument passed as stack is NULL\n");
		free(global.getlineBuffer);
		fclose(global.filePtr);
		exit(EXIT_FAILURE);
	}

	for (tmp = *stack; tmp && tmp->n; tmp = tmp->prev)
	{
		if (tmp->n >= 0 && tmp->n < 128)
			printf("%c", tmp->n);
		else
			break;
	}
	printf("\n");
}


/**
 * rotlF - implement the rotl opcode (send top item to bottom)
 * @stack: pointer to stack top
 * @line_number: line n
 *
 * Return: void
 */
void rotlF(stack_t **stack, unsigned int __attribute__ ((unused)) line_number)
{
	stack_t *tmp, *tail;

	if (!stack) /* Sanity check */
	{
		fprintf(stderr, "Argument passed as stack is NULL\n");
		free(global.getlineBuffer);
		fclose(global.filePtr);
		exit(EXIT_FAILURE);
	}
	tmp = *stack, tail = *stack;
	if (!tmp || !tmp->prev)
		return;

	while (tmp->prev)
		tmp = tmp->prev;

	*stack = (*stack)->prev;
	(*stack)->next = NULL;
	tmp->prev = tail;
	tail->prev = NULL;
	tail->next = tmp;
}


/**
 * rotrF - implement the rotr opcode (send bottom item to top)
 * @stack: pointer to stack top
 * @line_number: line n
 *
 * Return: void
 */
void rotrF(stack_t **stack, unsigned int __attribute__ ((unused)) line_number)
{
	stack_t *tmp, *tail;

	if (!stack) /* Sanity check */
	{
		fprintf(stderr, "Argument passed as stack is NULL\n");
		free(global.getlineBuffer);
		fclose(global.filePtr);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	if (!tmp || !tmp->prev)
		return;

	while (tmp->prev)
		tmp = tmp->prev;

	tail = tmp->next;
	tail->prev = NULL;
	tmp->next = NULL;
	tmp->prev = *stack;
	(*stack)->next = tmp;
	*stack = tmp;
}

