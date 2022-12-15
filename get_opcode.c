#include "monty.h"

/**
 * getOpcode - get the function corresponding to each opcode
 * @stack: top of the stack
 * @token: opcode recieved as a token
 * @line_number: line number
 *
 * Return: function pointer on success
 */

void (*getOpcode(stack_t **stack, char *token, unsigned int line_number))(stack_t **, unsigned int)
{
	int i;
	instruction_t ar[] = {
		{"push", pushF},
		{"pall", pallF},
		{NULL, NULL}
	};

	for (i = 0; ar[i].opcode; i++)
	{
		if (strcmp(ar[i].opcode, token) == 0)
			return (ar[i].f);
	}
	fprintf(stderr, "L<%u>: unknown instruction %s\n", line_number, token);
	freeStack(*stack);
	free(global.getlineBuffer);
	fclose(global.filePtr);
	exit(EXIT_FAILURE);
}
