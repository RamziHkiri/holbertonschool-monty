#include "monty.h"
/**
 * main - entry point
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on Success
 */
int main(int argc, char *argv[])
{
	char *red = NULL;
	char *monty = NULL;
	unsigned int line_number = 0;
	size_t leng = 0;
	FILE *mtf;
	stack_t *stack = NULL;

	mtf = fopen(argv[1], "r");
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (!mtf)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&red, &leng, mtf) != -1)
	{
		line_number++;
		monty = strtok(red, " \t\n\r");

		if (strcmp(monty, "push") == 0)
		{
			push(&stack, line_number);
		}
		if (strcmp(monty, "pall") == 0)
		{
			pall(&stack, line_number);
		}
	}
	free_stack(&stack);
	free(monty);
	fclose(mtf);
	return (0);
}
