#include "monty.h"

instruction_t instructions[] =
{
	{"push", op_push},
	{"pall", op_pall}
};

#define NUM_INSTRUCTIONS (sizeof(instructions) / sizeof(instruction_t))

void execute_opcode(char *opcode, int op_arg)
{
	int i;

	for (i = 0; i < NUM_INSTRUCTIONS; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, op_arg);
			return;
		}
	}
	printf("Unknown opcode '%s' at line %d\n", opcode, line_number);
}
