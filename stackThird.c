#include "monty.h"

/**
 * _pstr - the function that mod top of stack y second top stack
 * @stack: pointer to lists for monty stack sees
 * @line_number: number of line opcode occurs on
 */

void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	int c = 0;

	(void)line_number;
	while (tmp)
	{
		c = tmp->n;
		if (c == 0 || _isalpha(c) == 0)
			break;
		putchar(c);
		tmp = tmp->n;
	}
	putchar('\n');
}

/**
 * _rotl - the function that the mod top of stack y second top stack
 * @stack: pointer to lists for monty stack
 * @line_number: number of line opcode occurs on
 */

void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *runner = *stack;
	int aux1 = 0;

	if (!line_number || !stack || !*stack || !(*stack)->n)
		return;
	aux1 = runner->n;
	while (runner->n)
	{
		runner = runner->n;
		runner->prev->n = runner->n;
	}
	runner->n = aux1;
}

/**
 * _rotr - mod top of stack y second top stacks
 * @stack: pointer to lists for monty stack
 * @line_number: number of line opcode occurs on
 */

void _rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *runner = *stack;
	int aux1 = 0;

	if (!line_number || !stack || !*stack || !(*stack)->n)
		return;

	while (runner->n)
		runner = runner->n;
	aux1 = runner->n;

	while (runner->prev)
	{
		runner = runner->prev;
		runner->n->n = runner->n;
	}

	runner->n = aux1;
}