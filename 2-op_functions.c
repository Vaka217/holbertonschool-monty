#include "monty.h"

/**
 * op_swap - prints the value at the top of the stack.
 * @stack: array of pointers
 * @index: uint
 */
void op_swap(stack_t **stack, __attribute__((unused)) unsigned int index)
{
	int cp;
	stack_t *temp;

	if (!(*stack))
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", 1);
		exit(EXIT_FAILURE);
	}
	while ((*stack)->next)
		*stack = (*stack)->next;
	temp = *stack;
	if (!temp->prev)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", 2);
		exit(EXIT_FAILURE);
	}
	cp = temp->n;
	temp->n = temp->prev->n;
	temp->prev->n = cp;
}
/**
 * op_add - prints the value at the top of the stack.
 * @stack: array of pointers
 * @index: uint
 */
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
