#include "monty.h"

void op_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new, *end = *stack;
	
	new = malloc(sizeof(stack_t));
	if (!new)
		return;
	new->n = line_number;
	new->next = NULL;
	if (end)
	{
		while (end->next)
			end = end->next;
		new->prev = end;
		end->next = new;
	}
	else
	{
		*stack = new;
		new->prev = NULL;
	}
}

void op_pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
/*	if (!*stack)
		return;
	while((*stack)->next)
		*stack = (*stack)->next;
	while ((*stack)->prev)
	{
		*stack = (*stack)->prev;
		printf("%u\n", (*stack)->n);
	}*/
		for (; line_number > 1; line_number--)
		(*stack) = (*stack)->next;
	while (*stack)
	{
		printf("%u\n", (*stack)->n);
		(*stack) = (*stack)->prev;
	}
}
