#include "monty.h"

/**
 * free_stack - frees a stack
 * @stack: head of the stack
 *
 * Return: Nothing
 */
void free_stack(stack_t *stack)
{
	if (stack != NULL)
	{
		if (stack->next != NULL)
			free_stack(stack->next);

		free(stack);
	}
}
