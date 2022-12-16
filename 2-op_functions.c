#include "monty.h"

/**
 * op_swap - prints the value at the top of the stack.
 * @stack: array of pointers
 * @line_number: uint
 */
void op_swap(stack_t **stack, unsigned int line_number)
{
	int cp;
	stack_t *temp;

	if (!(*stack))
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	while (temp->next)
		temp = temp->next;
	if (!temp->prev)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	cp = temp->n;
	temp->n = temp->prev->n;
	temp->prev->n = cp;
}
/**
 * op_add - prints the value at the top of the stack.
 * @stack: array of pointers
 * @line_number: uint
 */
void op_add(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	while ((*stack)->next)
		(*stack) = (*stack)->next;
	if (!(*stack)->prev)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->prev->n += (*stack)->n;
	op_pop(stack, line_number);
}
