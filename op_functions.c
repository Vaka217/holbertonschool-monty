#include "monty.h"
/**
 * op_push - pushes an element to the stack
 * @stack: Doubly linked list.
 * @line_number: Number of the current line.
 */
void op_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL, *end = *stack;
	int num = 0;
	char *numstr = NULL;

	numstr = strtok(NULL, " \t\n");
	if (!numstr || isNumber(numstr) == 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	num = atoi(numstr);
	new = malloc(sizeof(stack_t));
	if (!new)
		return;
	new->n = num;
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
 * @stack: Doubly linked list.
 * @line_number: Number of the current line.
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
 * @stack: Doubly linked list.
 * @line_number: Number of the current line.
 */
void op_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	while (temp->next)
		temp = temp->next;
	printf("%d\n", temp->n);
}
/**
 * op_pop - deletes the current top of the stack.
 * @stack: Doubly linked list.
 * @line_number: Number of the current line.
 */
void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack, *delete;

	if (!*stack || !stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (!node->next)
	{
		free(node);
		*stack = NULL;
	}
	else
		while (node->next->next)
			node = node->next;
	delete = node->next;
	node->next = NULL;
	free(delete);
}
/**
 * total_free - free all.
 * @stack: Doubly linked list to be free.
 */
void total_free(stack_t *stack)
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
