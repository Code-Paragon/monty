#include "monty.h"

/**
 * op_push - the push opcode function
 * @stack: double pointer to the stack
 * @op_arg: the number to be pushed
 *
 * Return: void
 */
void op_push(stack_t **stack, unsigned int op_arg)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = op_arg;
	new_node->prev = NULL;

	if (*stack == NULL)
		new_node->next = NULL;
	else
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}

	*stack = new_node;
}

/**
 * op_pall - the pall opcode function, displays the stack
 * @stack: double pointer to the stack
 * @op_arg: the number to be printed
 *
 * Return: void
 */
void op_pall(stack_t **stack, unsigned int op_arg __attribute__((unused)))
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * op_pop -  removes the top element of the stack.
 * @stack: double pointer to the stack
 * @op_arg: the number to be printed
 *
 * Return: void
 */
void op_pop(stack_t **stack, unsigned int op_arg __attribute__((unused)))
{
	stack_t *temp = *stack;
	*stack = (*stack)->next;

	if (*stack == NULL)
		exit(0);
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}
