#include "monty.h"

void op_swap(stack_t **stack, __attribute__((unused)) unsigned int index)
{
	int cp;

	while ((*stack)->next)
		(*stack) = (*stack)->next;
	if (!*stack || !(*stack)->prev)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", 1);
		exit(EXIT_FAILURE);
	}
	cp = (*stack)->n;
	(*stack)->n = (*stack)->prev->n;
	(*stack)->prev->n = cp;
}
