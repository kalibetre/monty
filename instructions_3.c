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

/**
 * pstr - pstr opcode instruction
 * @stack: the stack
 * @line_number: line number
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	(void)line_number;

	node = stack != NULL ? *stack : NULL;
	while (node != NULL && node->n >= 32 && node->n <= 126)
	{
		printf("%c", (char)(node->n));
		node = node->next;
	}
	printf("\n");
}

/**
 * rotl - rotate left opcode instruction
 * @stack: the stack
 * @line_number: line number
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if (stack != NULL && *stack != NULL)
	{
		add_node_end(stack, (*stack)->n);
		delete_node_front(stack);
	}
}

/**
 * rotr - rotate right opcode instruction
 * @stack: the stack
 * @line_number: line number
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int end;

	(void)line_number;
	if (stack != NULL && *stack != NULL)
	{
		temp = *stack;
		while (temp->next != NULL)
			temp = temp->next;
		end = temp->n;
		delete_node_end(stack);
		add_node_front(stack, end);
	}
}
