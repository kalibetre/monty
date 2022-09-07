#include "monty.h"
/**
 * pop - pop opcode instruction
 * @stack: the stack
 * @line_number: line number
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	(void) line_number;
	if (*stack != NULL)
	{
		node = *stack;
		*stack = node->next;
		if (*stack != NULL)
			(*stack)->prev = NULL;
		free(node);
	}
}

/**
 * push - push opcode instruction
 * @stack: the stack
 * @line_number: line number
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *args = NULL;
	stack_t *node;

	args = strtok(NULL, " ");
	if (!isnumber(args))
	{
		free(*stack);
		invalid_int_arg(line_number);
	}

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		free(stack);
		malloc_error();
	}

	node->n = atoi(args);
	node->prev = NULL;
	node->next = NULL;
	if (*stack != NULL)
	{
		(*stack)->prev = node;
		node->next = *stack;
	}
	*stack = node;
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
	(void)line_number;

	if (stack == NULL || *stack == NULL)
		stack_empty_error(line_number);

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
