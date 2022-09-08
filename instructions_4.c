#include "monty.h"

/**
 * _stack - stack opcode instruction
 * @stack: the stack
 * @line_number: line number
 */
void _stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	app_state.mode = STACK;
}

/**
 * _queue - queue opcode instruction
 * @stack: the stack
 * @line_number: line number
 */
void _queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	app_state.mode = QUEUE;
}
