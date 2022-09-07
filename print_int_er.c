#include "monty.h"

/**
 * print_int_er - error message for invalid int arg
 * @num: the line number that the error occurred
 */
void print_int_er(int num)
{
	char digit_str[2];
	double factor = 1;
	int digit;

	while (num / factor >= 10)
		factor *= 10;

	digit_str[1] = '\0';
	while (factor >= 1)
	{
		digit = num / factor;
		digit_str[0] = digit + '0';
		write(STDERR_FILENO, digit_str, 1);
		num = num - digit * factor;
		factor /= 10;
	}
}
