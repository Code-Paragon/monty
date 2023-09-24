#include "monty.h"

/**
 * execute_opcode - function executes the opcode
 * @opcode: the command to be executed
 * @op_arg: the number to be operated
 * @stack: double pointer to the stack to operate on
 * @linecount: the line number
 *
 * Return: void
 */
void execute_opcode(char *opcode, int op_arg, stack_t **stack, int linecount)
{
	unsigned int i;
	instruction_t instructions[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pop", op_pop},
		{"add", op_add},
		{"nop", op_nop},
	};

	for (i = 0; i < NUM_INSTRUCTIONS; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, op_arg);
			return;
		}
	}
	printf("L%d: unknown instruction %s\n", linecount, opcode);
	exit(EXIT_FAILURE);
}
