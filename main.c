#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int ac, char **av)
{
	FILE *fp;
	char *s = NULL, *tokenized = NULL;
	int check = 0;
	size_t n = 0;

	if (ac != 2)
	{
		printf("Usage: monty <filename>\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(av[1], "r");
	if (!fp)
	{
		fprintf(stderr, "Couldn't open file\n");
		exit(EXIT_FAILURE);
	}
	while (check != -1)
	{
		check = getline(&s, &n, fp);
		if (check != -1)
		{
			tokenized = strtok(s, " \n\t");
			printf("token = %s\n", tokenized);
		}
	}
	fclose(fp);
	if (s)
		free (s);
	return (0);
}
