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
		stack_to_short_error("swap", line_number);

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

/**
 * add - add opcode instruction
 * @stack: the stack
 * @line_number: line number
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		stack_to_short_error("add", line_number);

	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}

/**
 * sub - sub opcode instruction
 * @stack: the stack
 * @line_number: line number
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		stack_to_short_error("sub", line_number);

	(*stack)->next->n -= (*stack)->n;
	pop(stack, line_number);
}

/**
 * _div - div opcode instruction
 * @stack: the stack
 * @line_number: line number
 */
void _div(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		stack_to_short_error("div", line_number);

	if ((*stack)->n == 0)
		div_by_zero_error(line_number);

	(*stack)->next->n /= (*stack)->n;
	pop(stack, line_number);
}

/**
 * mul - mul opcode instruction
 * @stack: the stack
 * @line_number: line number
 */
void mul(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		stack_to_short_error("div", line_number);

	(*stack)->next->n *= (*stack)->n;
	pop(stack, line_number);
}
