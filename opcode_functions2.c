#include "monty.h"
/**
 * swap_function - swap the tow last node values
 *
 *@tail: ptr to top node
 *@line_number: line number of monty file
 *
 */
void swap_function(stack_t **tail, unsigned int line_number)
{
	int aux = 0;

	stack_t *tmp = NULL;

	if (tail)
	{
		if ((*tail)->prev)
		{
			tmp = (*tail)->prev;
			aux = tmp->n;
			tmp->n = (*tail)->n;
			(*tail)->n = aux;
		}
	}

	else
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		freeStack(*tail);
		free(global.getlineBuffer);
		fclose(global.filePtr);

		exit(EXIT_FAILURE);
	}
}
/**
 * pop_function - deletes and reasign the top node
 *
 *@tail: top ptr
 *@line_number: line_number.
 *
 */
void pop_function(stack_t **tail, unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (*tail)
	{
		tmp = (*tail)->prev;
		free(*tail);
		*tail = tmp;
		(*tail)->next = NULL;
	}

	else
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		freeStack(*tail);
		free(global.getlineBuffer);
		fclose(global.filePtr);

		exit(EXIT_FAILURE);
	}
}
/**
 * add_function - add and reasign the top node
 *
 *@tail: top ptr
 *@line_number: line number
 *
 */
void add_function(stack_t **tail, unsigned int line_number)
{
	stack_t *tmp = NULL;
	int aux = 0;

	if (tail)
	{
		aux = (*tail)->n;

		if ((*tail)->prev)
		{
			tmp = (*tail)->prev;
			tmp->n += aux;
			pop_function(tail, line_number);
		}
	}

	else
	{
		fprintf(stderr, "L%u: can't add, stack empty\n", line_number);
		freeStack(*tail);
		free(global.getlineBuffer);
		fclose(global.filePtr);

		exit(EXIT_FAILURE);
	}
}
/**
 * nop_function - this function makes nothing
 *
 *@tail: tail ptr
 *@line_number: line number.
 */
void nop_function(stack_t __attribute__ ((unused)) **tail,
	unsigned int __attribute__ ((unused)) line_number)
{
}
