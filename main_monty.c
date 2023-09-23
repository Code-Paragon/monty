#include "monty.h"

/**
 * read_line - reads lines from file one at a time and dynamically allocates memory for it
 * @file: file to read from
 *
 * Return: line read
 */
char* read_line(FILE* file)
{
	int c, buffer_size = BUFFER_SIZE;
	char *line, *position;

	line = (char*)malloc(buffer_size * sizeof(char));
	if (!line)
	{
		fprintf(stderr, "read_line Memory allocation error");
		exit(EXIT_FAILURE);
	}

	position = line;
	while(1)
	{
		c = fgetc(file);

		if (c == EOF || c == '\n')
		{
			*position = '\0';
			return line;
		}

		*position = (char)c;
		position++;

		/*If the buffer is full, reallocate more memory*/
		if (position - line >= buffer_size - 1)
		{
			buffer_size *= 2;
			line = (char*)realloc(line, buffer_size * sizeof(char));

			if (!line)
			{
				fprintf(stderr, "read_line Memory allocation error");
				exit(EXIT_FAILURE);
			}
			position = line + buffer_size / 2 - 1;
		}
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
	char *line;
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

	while ((line = read_line(file)) != NULL)
	{
		linecount++;
		if (strcmp(line, "\0") == 0)
		{
			continue;
			free(line);
		}
		handleLines(line, &stack, linecount);
		free(line);
	}

	fclose(file);
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
	char *opcode, *op_argstr, *pall;
	char delimiters[] = " $";
	unsigned int op_arg;

	pall = "pall";
	opcode = strtok(line, delimiters);
	op_argstr = strtok(NULL, delimiters);
	op_arg = atoi(op_argstr);

	if (strcmp(opcode, pall) != 0)
	{
		if (op_arg == 0 && op_argstr == NULL)
		{
			fprintf(stderr, "L%d: usage: push integer\n", linecount);
			exit(EXIT_FAILURE);
		}
	}
	execute_opcode(opcode, op_arg, stack, linecount);
}
