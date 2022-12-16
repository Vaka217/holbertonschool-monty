#include "monty.h"

/**
 * isNumber - checks if a string is a number
 * @s: String to check
 *
 * Return: 1 if its a number, 0 otherwise.
 */
int isNumber(char s[])
{
	int i = 0;

	if (s[0] == '-')
		s[0] = '0';
	for (i = 0; s[i]; i++)
		if (!isdigit(s[i]))
			return (0);
	return (1);
}
/**
 * getopc - Gets the opcode function needed.
 * @opc: Opcode name
 *
 * Return: The function of the given opcode or NULL.
 */
void (*getopc(char *opc))(stack_t **stack, unsigned int line_number)
{
	instruction_t instructions[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{NULL, NULL},
	};
	int i = 0;

	for (i = 0; instructions[i].opcode; i++)
	{
		if (strcmp(opc, instructions[i].opcode) == 0)
			return (instructions[i].f);
	}
	return (instructions[i].f);
}
/**
 * main - main function
 * @argc: Number of arguments
 * @argv: Array of arguments
 *
 * Return: 0
 */
int main(int argc, char **argv)
{
	FILE *fp = NULL;
	char *buffer = NULL, *opc = NULL;
	int inputs = 0;
	size_t bufsize = 0;
	stack_t *stack = NULL;
	void (*f)(stack_t **stack, unsigned int line_num);

	if (argc != 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	fp = fopen(argv[1], "r");
	if (!fp)
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]), exit(EXIT_FAILURE);
	while (getline(&buffer, &bufsize, fp) != -1)
	{
		inputs++;
		opc = strtok(buffer, " \t\n");
		if (!opc || strcmp(opc, "nop") == 0 || strcmp(opc, "\n") == 0)
			continue;
		f = getopc(opc);
		if (!f)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", inputs, opc);
			exit(EXIT_FAILURE);
		}
		f(&stack, inputs);
	}
	free(buffer);
	fclose(fp);
	total_free(stack);
	return (0); }
