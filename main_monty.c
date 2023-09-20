#include "monty.h"

/**
  * main - this is the main functuon that interpretes Monty BytesCodes files
  * @argc: number of arguments
  * @argv: array of arguments
  *
  * Return: 0 if Successful and 1 on error
  */
void handleLines(line);
int main(int argc, char *argv[])
{
	const char *filename;
	char line[10];

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	filename = argv[1];
	FILE *file = fopen(filename, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file % %s\n", filename);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), file) != NULL)
	{
		handleLines(line);
	}
	fclose(file);
	return (0);
}

void handleLines(line)
{
	char *opcode, *op_argstr;
	char delimiters[] = " ";
	int op_arg;

	opcode = strtok(line, delimiters);
	op_argstr = strtok(NULL, delimiters);
	op_arg = atoi(op_argstr);

}
