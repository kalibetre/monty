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
		invalid_int_arg(line_number);

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		malloc_error();

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
