#include "monty.h"

/**
 * interpret_file - reads a monty bytecode file
 * @filename: the name of the file
 *
 * Return: Nothing
 */
void interpret_file(char *filename)
{
	int fd, line_count = 1;
	char *line = NULL, *token;
	size_t line_len = 0;
	const char *sep = " ";
	void (*f)(stack_t **, unsigned int);
	stack_t *stack = NULL;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		failed_to_open_file(filename);

	while (_getline(&line, &line_len, fd) != -1)
	{
		if (line_len > 0)
		{
			token = strtok(line, sep);
			if (token != NULL)
			{
				f = get_instruction(token);
				if (f == NULL)
					invalid_instruction(line_count, token);
				f(&stack, line_count);
				line_count++;
			}
			free(line);
		}
	}
	close(fd);
}
