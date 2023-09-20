#include <string.h>
#include "monty.h"

#define INITIAL_BUFFER_SIZE 100

void handleLine (char *line);
/**
 * main - this is the main functuon that interpretes Monty BytesCodes files
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 if Successful and 1 on error
 */
int main(int argc, char *argv[])
{
	char *line;
	size_t buffer_size;
	const char *filename;
/*Check if no file or more than one argument passed*/
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	line = (char *)malloc(INITIAL_BUFFER_SIZE * sizeof(char));
	buffer_size = INITIAL_BUFFER_SIZE;
	/*Open the bytecode file for reading*/
	filename = argv[1];
	FILE *file = fopen(filename, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		free(file);
		exit(EXIT_FAILURE);
	}
	/* Read lines one at a time */
	while (getline(&line, &buffer_size, file) != -1)
	{
		handleLine(line);
	}
	free(line);

	fclose(file);
	return (0);
}

void handleLine(char *line)
{
	char *token;
	char *opcode;
	char *argument;

	/*Tokenize the line based on whitespace*/
	token = strtok(line, " \t\n");

	if (token == NULL)
		continue;
	/*The first token is the opcode*/
	opcode = strdup(token);
	/*The second token (if present) is the argument*/
	token = strtok(NULL, "\t\n");
	if (token != NULL)
		argument = strdup(token);
	else
		argument = NULL;
	/*Execute the opcode with the argument*/
	execute_opcode(opcode, argument);
	free(opcode);
}
