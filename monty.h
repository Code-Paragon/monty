#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 128
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

#define NUM_INSTRUCTIONS (sizeof(instructions) / sizeof(instruction_t))

char *read_line(FILE *file);
void op_push(stack_t **stack, unsigned int op_arg);
void op_pall(stack_t **stack, unsigned int op_arg __attribute__((unused)));
void op_pop(stack_t **stack, unsigned int op_arg __attribute__((unused)));
void execute_opcode(char *opcode, int op_arg, stack_t **stack, int linecount);
void handleLines(char *line, stack_t **stack, int linecount);
void op_add(stack_t **stack, unsigned int op_arg __attribute__((unused)));
void op_nop(stack_t **stack, unsigned int op_arg __attribute__((unused)));

#endif /* _MONTY_H_ */
