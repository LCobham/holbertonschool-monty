#include "monty.h"

/**
 * getOpcode - get the function corresponding to each opcode
 * @s: top of the stack
 * @t: opcode recieved as a token
 * @ln: line number
 *
 * Return: function pointer on success
 */

void (*getOcd(stack_t **s, char *t, unsigned int ln))(stack_t **, unsigned int)
{
	int i;
	instruction_t ar[] = {
		{"push", pushF},
		{"pall", pallF},
		{"pint", pintF},
		{"swap", swap_function},
		{"pop", pop_function},
		{NULL, NULL}
	};

	for (i = 0; ar[i].opcode; i++)
	{
		if (strcmp(ar[i].opcode, t) == 0)
			return (ar[i].f);
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", ln, t);
	freeStack(*s);
	free(global.getlineBuffer);
	fclose(global.filePtr);
	exit(EXIT_FAILURE);
}
