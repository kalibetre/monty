#include "monty.h"
/**
 * free_app_state - frees the app state
 *
 */
void free_app_state(void)
{
	if (app_state.line_buff != NULL)
		free(app_state.line_buff);

	if (app_state.stack != NULL)
		free_stack(app_state.stack);

	close(app_state.file_d);
}

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
