#include "monty.h"

/**
 * getOcd - get the function corresponding to each opcode
 * @s: top of the stack
 * @t: opcode recieved as a token
 * @l: line number
 *
 * Return: function pointer on success
 */

void (*getOcd(stack_t **s, char *t, unsigned int l))(stack_t **, unsigned int)
{
	int i;
	instruction_t ar[] = {
		{"push", pushF},
		{"pall", pallF},
		{"pint", pintF},
		{"swap", swap_function},
		{"pop", pop_function},
		{"add", add_function},
		{"nop", nop_function},
		{"sub", subF},
		{"div", divF},
		{"mul", mulF},
		{"mod", modF},
		{NULL, NULL}
	};

	for (i = 0; ar[i].opcode; i++)
	{
		if (t[0] == '#')
			return (ar[6].f); /* If first char is #, return nop function */
		if (strcmp(ar[i].opcode, t) == 0)
			return (ar[i].f);
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", l, t);
	freeStack(*s);
	free(global.getlineBuffer);
	fclose(global.filePtr);
	exit(EXIT_FAILURE);
}
