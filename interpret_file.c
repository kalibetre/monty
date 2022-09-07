#include "monty.h"

/**
 * interpret_file - reads a monty bytecode file
 *
 * Return: Nothing
 */
void interpret_file(void)
{
	int line_count = 1;
	char *token;
	size_t line_len = 0;
	const char *sep = " \t";
	void (*f)(stack_t **, unsigned int);

	app_state.line_buff = NULL;
	while (_getline(&app_state.line_buff, &line_len, app_state.file_d) != -1)
	{
		if (line_len > 0)
		{
			token = strtok(app_state.line_buff, sep);
			if (token != NULL)
			{
				f = get_instruction(token);
				if (f == NULL)
					invalid_instruction(line_count, token);

				f(&app_state.stack, line_count);
			}
		}
		free(app_state.line_buff);
		app_state.line_buff = NULL;
		line_count++;
	}
	free_app_state();
	exit(EXIT_SUCCESS);
}
