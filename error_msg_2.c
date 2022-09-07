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
