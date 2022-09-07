#include "monty.h"

/**
 * main - prints the number of arguments passed to the program
 * @argc: the number of arguments passed to main
 * @argv: the value of arguments passed to main
 *
 * Return: Always 0
 */
int main(int argc, char **argv)
{
	if (argc != 2)
		invalid_argument();

	interpret_file(argv[1]);
	return (0);
}
