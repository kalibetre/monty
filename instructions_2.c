#include "monty.h"

/**
 * swap - swap opcode instruction
 * @stack: the stack
 * @line_number: line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		swap_error(line_number);

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

/**
 * add - swap opcode instruction
 * @stack: the stack
 * @line_number: line number
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		add_error(line_number);

	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}
