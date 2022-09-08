#include "monty.h"

/**
 * mod - mod opcode instruction
 * @stack: the stack
 * @line_number: line number
 */
void mod(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		stack_to_short_error("mod", line_number);

	if ((*stack)->n == 0)
		div_by_zero_error(line_number);

	(*stack)->next->n %= (*stack)->n;
	pop(stack, line_number);
}

/**
 * pchar - pchar opcode instruction
 * @stack: the stack
 * @line_number: line number
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		stack_empty_error("pchar", line_number);

	if ((*stack)->n >= 32 && (*stack)->n <= 126)
		printf("%c\n", (char)(*stack)->n);
	else
		ascii_error(line_number);
}
