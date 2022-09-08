#include "monty.h"

app_state_t app_state;

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

	app_state.line_buff = NULL;
	app_state.file_d = open(argv[1], O_RDONLY);
	if (app_state.file_d == -1)
		failed_to_open_file(argv[1]);
	app_state.stack = NULL;
	app_state.mode = STACK;

	interpret_file();
	return (0);
}
