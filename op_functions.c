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
	stack_t *temp = *stack;

	while (temp->next)
		temp = temp->next;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->prev;
	}
}
