#include "monty.h"

/**
 * interpret_file - reads a monty bytecode file
 *
 * Return: Nothing
 */
void interpret_file(void)
{
	int line_count = 1, eof;
	char *token;
	size_t line_len = 0;
	const char *sep = " \t";

	app_state.line_buff = NULL;
	do {
		eof = _getline(&app_state.line_buff, &line_len, app_state.file_d);

		if (eof == -1)
			failed_to_read_line();

		if (line_len > 0)
		{
			token = strtok(app_state.line_buff, sep);
			if (token != NULL && token[0] != '#')
				get_instruction(token, line_count)(&app_state.stack, line_count);
		}
		free(app_state.line_buff);
		app_state.line_buff = NULL;
		line_count++;
	} while (eof == 0);

	free_app_state();
}
