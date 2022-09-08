#include "monty.h"

/**
 * ascii_error - error message for non ascii chars
 * @l_num: the line number that the error occurred
 */
void ascii_error(int l_num)
{
	fprintf(stderr, "L%u: can't pchar, value out of range\n", l_num);
	free_app_state();
	exit(EXIT_FAILURE);
}
