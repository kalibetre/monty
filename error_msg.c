#include "monty.h"

/**
 * invalid_argument - error message for invalid program arguments
 */
void invalid_argument(void)
{
	const char *str = "USAGE: monty file\n";

	write(STDERR_FILENO, str, strlen(str));
	exit(EXIT_FAILURE);
}

/**
 * failed_to_open_file - error message for failed file read
 * @filename: name of the file
 */
void failed_to_open_file(char *filename)
{
	const char *str = "Error: Can't open file ";

	write(STDERR_FILENO, str, strlen(str));
	write(STDERR_FILENO, filename, strlen(filename));
	write(STDERR_FILENO, "\n", 1);
	exit(EXIT_FAILURE);
}

/**
 * invalid_instruction - error message for invalid instruction
 * @line_number: the line number that the error occurred
 * @opcode: the operation code
 */
void invalid_instruction(int line_number, char *opcode)
{
	const char *str = ": unknown instruction ";
	char digit_str[2];
	double factor = 1;
	int digit;

	while (line_number / factor >= 10)
		factor *= 10;

	write(STDERR_FILENO, "L", 1);

	digit_str[1] = '\0';
	while (factor >= 1)
	{
		digit = line_number / factor;
		digit_str[0] = digit + '0';
		write(STDERR_FILENO, digit_str, 1);
		line_number = line_number - digit * factor;
		factor /= 10;
	}

	write(STDERR_FILENO, str, strlen(str));
	write(STDERR_FILENO, opcode, strlen(opcode));
	write(STDERR_FILENO, "\n", 1);
	exit(EXIT_FAILURE);
}

/**
 * malloc_error - error message for malloc failure
 */
void malloc_error(void)
{
	const char *str = "Error: malloc failed\n";

	write(STDERR_FILENO, str, strlen(str));
	exit(EXIT_FAILURE);
}
