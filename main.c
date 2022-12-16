#include "monty.h"

global_t global = {NULL, NULL};

/**
 * main - run a Monty ByteCode file interpreter
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 on success
 */

int main(int ac, char **av)
{
	FILE *fp;
	char *s = NULL, *token = NULL;
	size_t n = 0;
	int check = 0;
	unsigned int line_number = 1;
	stack_t *stack = NULL;
	void (*fun)(stack_t **, unsigned int) = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(av[1], "r"), global.filePtr = fp;
	if (!fp)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while (check != -1)
	{
		check = getline(&s, &n, fp), global.getlineBuffer = s;
		if (check != -1)
		{
			token = strtok(s, " \n\t");
			if (token)
			{
				fun = getOcd(&stack, token, line_number);
				fun(&stack, line_number);
			}
		}
		line_number++;
	}
	freeStack(stack);
	free(s);
	fclose(fp);
	return (0);
}
