#include "monty.h"

void op_swap(stack_t **stack, __attribute__((unused)) unsigned int index)
{
	stack_t *swap;
	if (!*stack || !(*stack)->prev)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", 1);
		exit(EXIT_FAILURE);
	}
	swap = *stack;
	(*stack)->n = (*stack)->prev->n;
	(*stack)->prev->n = swap->n;
	free(swap);
}
