#define BUFFER_MAX_LENGTH 1024
#include "monty.h"

void getopc(char *line, stack_t **stack)
{
	instruction_t instructions[] = {
		{"push", op_push},
		{"pall", op_pall},
		{NULL, NULL},
	};
	int i = 0, num;
	char *opc = NULL;

	opc = strtok(line, " \t\n");
	if (strcmp(opc, "push") == 0)
		num = atoi(strtok(NULL, " \t"));
	for (i = 0; instructions[i].opcode; i++)
	{
		if (strcmp(opc, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, num);
		}
	}
/*	fprintf(stderr, "L%d: unknown instruction %s\n", num, opc);
	exit(EXIT_FAILURE);*/
}

int main(int argc, char* argv[])
{
    FILE *file = NULL;
    char line[BUFFER_MAX_LENGTH];
    int tempChar;
    unsigned int tempCharIdx = 0U;
    char *dynamicLine = NULL;
    stack_t *stack = NULL;

    if (argc == 2)
         file = fopen(argv[1], "r");
    else {
         fprintf(stderr, "error: wrong number of arguments\n"
                         "usage: %s textfile\n", argv[0]);
         return EXIT_FAILURE;
    }

    if (!file) {
         fprintf(stderr, "error: could not open textfile: %s\n", argv[1]);
         return EXIT_FAILURE;
    }

    while(tempChar = fgetc(file))
    {
        if (tempChar == EOF) {
            line[tempCharIdx] = '\0';
            dynamicLine = strdup(line);
            free(dynamicLine);
            dynamicLine = NULL;
            break;
        }
        else if (tempChar == '\n') {
            line[tempCharIdx] = '\0';
            tempCharIdx = 0U;
            dynamicLine = strdup(line);
            getopc(dynamicLine, &stack);
            free(dynamicLine);
            dynamicLine = NULL;
            continue;
        }
        else
            line[tempCharIdx++] = (char)tempChar;
    }
    return EXIT_SUCCESS;
}
