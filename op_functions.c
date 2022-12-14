#include "monty.h"
/**
 * op_push - pushes an element to the stack
 * @stack: array of pointers
 * @line_number: uint
 */
void op_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL, *end = *stack;

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
/**
 * op_pall - prints all the values on the stack
 * @stack: array of pointers
 * @line_number: uint
 */
void op_pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *temp;

	if (!*stack)
		return;
	temp = *stack;
	while (temp->next)
		temp = temp->next;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->prev;
	}
}
/**
 * op_pint - prints the value at the top of the stack.
 * @stack: array of pointers
 * @line_number: uint
 */
void op_pint(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *temp;

	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", 1);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	while (temp->next)
		temp = temp->next;
	printf("%d\n", temp->n);
}

void op_pop(stack_t **stack, unsigned int index)
{
	stack_t *prev, *sig, *delete;
	unsigned int i = 0;

	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", 1);
		exit(EXIT_FAILURE);
	}	
	delete = *stack;
	if (index == 0)
	{
		*stack = (*stack)->next, (*stack)->prev = NULL;
		free(delete);
		return;
	}
	for (i = 0; delete; delete = delete->next)
		i++;
	if (index > i)
		return;
	delete = *stack;
	for (i = 0; i < index; i++)
		delete = delete->next;
	if (!delete->prev && !delete->next)
	{
		free(delete);
		return;
	}
	if (!delete->prev && delete->next)
	{
		sig = delete->next, sig->prev = NULL, delete->next = NULL;
		free(delete);
		return;
	}
	if (!delete->next && delete->prev)
	{
		prev = delete->prev, prev->next = NULL, delete->prev = NULL;
		free(delete);
		return;
	}
	prev = delete->prev, sig = delete->next, sig->prev = prev;
	prev->next = sig, delete->next = NULL, delete->prev = NULL, free(delete);
	return;
}
/**
 * total_free - frees
 */
void total_free(void)
{
	stack_t *to_be_free;
	stack_t *temp = NULL;

	to_be_free = stack;

	while (to_be_free)
	{
		temp = to_be_free->next;

		free(to_be_free);

		to_be_free = temp;
	}
}
