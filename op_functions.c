#include "monty.h"

void op_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = malloc(sizeof(stack_t)), *end = *stack;

	if (!new)
		return;
	new->n = line_number;
	new->next = NULL;
	new->prev = NULL;
	if (!*stack)
	{
		*stack = new;
	}
	else
	{
		while (end->next)
			end = end->next;
		end->next = new;
		new->prev = end;
	}
}

void op_pall(stack_t **stack, unsigned int line_number)
{
	for (; line_number > 1; line_number--)
		(*stack) = (*stack)->next;
	while (*stack)
	{
		printf("%u\n", (*stack)->n);
		(*stack) = (*stack)->prev;
	}
}
