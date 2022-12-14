#include "monty.h"

void op_swap(stack_t **stack, __attribute__((unused)) unsigned int index)
{
	int cp;

	if (!*stack)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", 1);
		exit(EXIT_FAILURE);
	}
	while ((*stack)->next)
		(*stack) = (*stack)->next;	
	if (!(*stack)->prev)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", 2);
		exit(EXIT_FAILURE);
	}
	cp = (*stack)->n;
	(*stack)->n = (*stack)->prev->n;
	(*stack)->prev->n = cp;
}

void op_add(stack_t **stack, __attribute__((unused)) unsigned int index)
{
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", 1);
		exit(EXIT_FAILURE);
	}
	while ((*stack)->next)
		(*stack) = (*stack)->next;	
	if (!(*stack)->prev)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", 2);
		exit(EXIT_FAILURE);
	}
	(*stack)->prev->n += (*stack)->n;
	op_pop(stack, index);
}
