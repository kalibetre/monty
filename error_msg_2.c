#include "monty.h"

/**
 * pint_error - error message for pint on empty stack
 * @l_num: the line number that the error occurred
 */
void pint_error(int l_num)
{
	fprintf(stderr, "L%u: can't pint, stack empty\n", l_num);
	free_app_state();
	exit(EXIT_FAILURE);
}

/**
 * pop_error - error message for pop empty stack
 * @l_num: the line number that the error occurred
 */
void pop_error(int l_num)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", l_num);
	free_app_state();
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

/**
 * stack_to_short_error - error message for add on stack to short
 * @l_num: the line number that the error occurred
 * @msg: operation name
 */
void stack_to_short_error(const char *msg, int l_num)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", l_num, msg);
	free_app_state();
	exit(EXIT_FAILURE);
}

/**
 * div_by_zero_error - error message for div by 0
 * @l_num: the line number that the error occurred
 */
void div_by_zero_error(int l_num)
{
	fprintf(stderr, "L%u: division by zero\n", l_num);
	free_app_state();
	exit(EXIT_FAILURE);
}
