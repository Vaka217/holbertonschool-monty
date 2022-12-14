#include "monty.h"

stack_t *stack = NULL;
int isNumber(char s[]) 
{ 
    if (s[0] == '-')
	    s[0] = '0';
    for (int i = 0; s[i]; i++) 
        if (!isdigit(s[i]))
            return 0; 
    return 1; 
}

void getopc(char *opc, int num, unsigned int line_num)
{
	instruction_t instructions[] = {
		{"push", op_push},
		{"pall", op_pall},
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

int main(int argc, char **argv)
{
	FILE *fp = NULL;
	char buffer[256], *opc = NULL, *token;
	int num = -1, inputs = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (!fp)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(buffer, 256, fp))
	{
		inputs++;
		if (strcmp(buffer, "\n") == 0) /* if only newline is passed */
			continue;
		opc = strtok(buffer, " \t\n");
		if ((token = strtok(NULL, " \t\n")))
		{
			if (isNumber(token) == 1 && token[0] != '-')
				num = atoi(token);
			else if (isNumber(token) == 1 && token[0] == '-')
				num = -1 * (atoi(token));
			else
			{
				fprintf(stderr, "L%u: usage: push integer\n", inputs);
				exit(EXIT_FAILURE);
			}
		}
		getopc(opc, num, inputs);
	}
	fclose(fp);
	return(0);
}

