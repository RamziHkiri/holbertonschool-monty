#include "monty.h"
/**
 * push - insert an elment to the stack
 * @stack: the stack
 * @line_number: number of line red from the file
*/
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: stack not found\n", line_number);
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		free(new);
		free(monty2);
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	if (monty2 == NULL || _parseArg(monty2) == 0)
	{
		free(new);
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	if ((isdigit(*monty2) != 0) || (*monty2 == '-' && isdigit(monty2[1])))
		new->n = atoi(monty2);

	new->next = *stack;
	new->prev = NULL;
	if (*stack)
		(*stack)->prev = new;
	*stack = new;
}
/**
 * free_stack - free stack
 * @stack: stack to be fred
 */

void free_stack(stack_t **stack)
{
	stack_t *temp = NULL;

	if (stack == NULL || *stack == NULL)
		return;

	while (*stack != NULL)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}
/**
 * pall -print the content of the stack
 * @stack: doubly linked list (stack)
 * @line_number: number of red lines from the file
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	temp = *stack;
	(void)line_number;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * _parseArg - checks if the argument of push is a integer
 * @c: argument
 * Return: 1 on Success, or 0 on failure
 */
int _parseArg(char *c)
{
	int idx = 0;

	while (((c[idx] <= '9' && c[idx] >= '0') || (c[0] == '-')) && c != 0)
	{
		if (c[idx + 1] == 0)
			return (1);
		idx++;
	}
	return (0);
}
