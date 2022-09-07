#include "monty.h"

/**
 * invalid_argument - error message for invalid program arguments
 */
void invalid_argument(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	free_app_state();
	exit(EXIT_FAILURE);
}

/**
 * failed_to_open_file - error message for failed file read
 * @filename: name of the file
 */
void failed_to_open_file(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	free_app_state();
	exit(EXIT_FAILURE);
}

/**
 * invalid_instruction - error message for invalid instruction
 * @l_num: the line number that the error occurred
 * @opcode: the operation code
 */
void invalid_instruction(int l_num, char *opcode)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", l_num, opcode);
	free_app_state();
	exit(EXIT_FAILURE);
}

/**
 * malloc_error - error message for malloc failure
 */
void malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	free_app_state();
	exit(EXIT_FAILURE);
}

/**
 * invalid_int_arg - error message for invalid int arg
 * @l_num: the line number that the error occurred
 */
void invalid_int_arg(int l_num)
{
	fprintf(stderr, "L%u: usage: push integer\n", l_num);
	free_app_state();
	exit(EXIT_FAILURE);
}
