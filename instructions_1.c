#include "monty.h"

/**
 * pop - pop opcode instruction
 * @stack: the stack
 * @line_number: line number
 */
void pop(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		pop_error(line_number);

	if (app_state.mode == STACK)
		delete_node_front(stack);
	else
		delete_node_end(stack);
}

/**
 * push - push opcode instruction
 * @stack: the stack
 * @line_number: line number
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *args = NULL;

	args = strtok(NULL, " \t");
	if (args == NULL || !isnumber(args))
		invalid_int_arg(line_number);

	if (app_state.mode == STACK)
		add_node_front(stack, atoi(args));
	else
		add_node_end(stack, atoi(args));
}

/**
 * pall - pall opcode instruction
 * @stack: the stack
 * @line_number: line number
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;
	if (stack != NULL)
	{
		temp = *stack;
		while (temp != NULL)
		{
			printf("%d\n", temp->n);
			temp = temp->next;
		}
	}
}

/**
 * pint - pint opcode instruction
 * @stack: the stack
 * @line_number: line number
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		stack_empty_error("pint", line_number);

	printf("%d\n", (*stack)->n);
}

/**
 * nop - nop opcode instruction
 * @stack: the stack
 * @line_number: line number
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
