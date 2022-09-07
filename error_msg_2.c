#include "monty.h"

/**
 * stack_empty_error - error message for empty stack
 * @l_num: the line number that the error occurred
 */
void stack_empty_error(int l_num)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", l_num);
	exit(EXIT_FAILURE);
}

/**
 * failed_to_read_line - error message for failed file read
 */
void failed_to_read_line(void)
{
	fprintf(stderr, "Error: Can't read line\n");
	free_app_state();
	exit(EXIT_FAILURE);
}
