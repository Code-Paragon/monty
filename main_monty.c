#include "monty.h"

/**
 * cleanup_stack - cleans the stack node when program exits
 * @stack: stack to be cleaned
 *
 * Return: void
 */

void cleanup_stack(stack_t *stack)
{
	stack_t *current;

	current = stack;
	while (current != NULL)
	{
		stack_t *temp = current;

		current = current->next;
		free(temp);
	}
}

/**
 * main - this is the main functuon that interpretes Monty BytesCodes files
 * @opcode: the stack command to be executed
 * @op_arg: argument of opcode
 * @stack: double pointer to stack to be operated
 * @linecount: line number of bytecode file
 *
 * Return: 0 if Successful and 1 on error
 */
void execute_opcode(char *opcode, int op_arg, stack_t **stack, int linecount);
void handleLines(char *line, stack_t **stack, int linecount);

int main(int argc, char *argv[])
{
	const char *filename;
	FILE *file;
	char line[50];
	stack_t *stack = NULL;
	int linecount = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	filename = argv[1];
	file = fopen(filename, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), file) != NULL)
	{
		linecount++;
		handleLines(line, &stack, linecount);
	}

	fclose(file);

	cleanup_stack(stack);
	return (0);
}

/**
 * handleLines - the function that handles the lines read one at a time
 * @line: line read
 * @stack: double pointer to stack to be operated on
 * @linecount: the line number
 *
 * Return: void
 */
void handleLines(char *line, stack_t **stack, int linecount)
{
	char *opcode, *op_argstr;
	char delimiters[] = " $";
	unsigned int op_arg;

	if (line[0] == '\0' || strspn(line, " \t\n") == strlen(line))
		return;

	opcode = strtok(line, delimiters);
	op_argstr = strtok(NULL, delimiters);
	if (strcmp(op_argstr, "\n") == 0 && strcmp(opcode, "push") == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", linecount);
		exit(EXIT_FAILURE);
	}
	op_arg = atoi(op_argstr);
	execute_opcode(opcode, op_arg, stack, linecount);
}
