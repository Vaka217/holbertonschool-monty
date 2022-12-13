#include "monty.h"

stack_t *stack = NULL;
int isNumber(char s[]) 
{ 
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

	for (i = 0; instructions[i].opcode; i++)
	{
		if (strcmp(opc, instructions[i].opcode) == 0)
			instructions[i].f(&stack, num);
	}
	if (instructions[i].opcode == NULL)
	{
		fprintf(stderr, "L%u: unknown instruction %s", line_num, opc);
		exit(EXIT_FAILURE);
	}
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
		fprintf(stderr, "Error: Can't open file %s", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(buffer, 256, fp))
	{
		inputs++;
		opc = strtok(buffer, " \t\n");
		if ((token = strtok(NULL, " \t\n")))
		{
			if (isNumber(token) == 1)
				num = atoi(token);
			else
			{
				fprintf(stderr, "L%u: usage: push integer", inputs);
				exit(EXIT_FAILURE);
			}
		}
		getopc(opc, num, inputs);
	}
	fclose(fp);
	return(0);
}

