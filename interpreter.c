#include "monty.h"

stack_t *stack = NULL;
/**
 * isNumber - checks kadsk
 * @s: array
 * Return: 1
 */
int isNumber(char s[])
{
	if (s[0] == '-')
		s[0] = '0';
	for (int i = 0; s[i]; i++)
		if (!isdigit(s[i]))
			return (0);
	return (1);
}
/**
 * getopc - s
 * @opc: array
 * @num: int
 * @line_num: uint
 */
void getopc(char *opc, int num, unsigned int line_num)
{
	instruction_t instructions[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{NULL, NULL},
	};
	int i = 0;

	if (num == -1 && strcmp(opc, "push") == 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}

	for (i = 0; instructions[i].opcode; i++)
	{
		if (!opc)
			return;
		if (strcmp(opc, instructions[i].opcode) == 0)
		{
			instructions[i].f(&stack, num);
			return;
		}
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_num, opc);
	exit(EXIT_FAILURE);
}
/**
 * main - sad
 * @argc: argc
 * @argv: argv
 * Return: 0
 */
int main(int argc, char **argv)
{
	FILE *fp = NULL;
	char buffer[256], *opc = NULL, *token;
	int num = -1, inputs = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE); }
	fp = fopen(argv[1], "r");
	if (!fp)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE); }
	while (fgets(buffer, 256, fp))
	{
		inputs++;
		if (strcmp(buffer, "\n") == 0) /* if only newline is passed */
			continue;
		opc = strtok(buffer, " \t\n");
		if (opc)
		{
			token = strtok(NULL, " \t\n");
			if (token && strcmp("push", opc) == 0)
			{
				if (isNumber(token) == 1 && token[0] != '-')
					num = atoi(token);
				else if (isNumber(token) == 1 && token[0] == '-')
					num = -1 * (atoi(token));
				else
				{
					fprintf(stderr, "L%u: usage: push integer\n", inputs);
					exit(EXIT_FAILURE); } }
			else if (strcmp("push", opc) == 0)
			{
				fprintf(stderr, "L%u: usage: push integer\n", inputs);
				exit(EXIT_FAILURE); }
			getopc(opc, num, inputs); } }
	total_free(), fclose(fp);
	return (0); }

