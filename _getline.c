#include "monty.h"

/**
 * _getline - reads a line from the standard input
 * @line: pointer to the line to be read
 * @line_n: number of bytes read
 * @fd: file descriptor
 *
 * Return: -1 if it failed otherwise 0
 */
int _getline(char **line, size_t *line_n, int fd)
{
	char buffer[1024], c;
	int byte_count = 0;
	ssize_t buffer_rd = 0;
	*line_n = 0;
	do {
		buffer_rd = read(fd, &c, 1);

		if (buffer_rd == -1)
			return (-1);

		if ((buffer_rd == 0 && byte_count > 0) || c == '\n')
		{
			buffer[byte_count++] = '\0';
			*line = malloc(sizeof(char) * byte_count);
			(*line)[0] = '\0';
			*line = strcat(*line, buffer);
			*line_n = byte_count - 1;

			if (buffer_rd == 0)
				return (1);
			break;
		}

		buffer[byte_count++] = c;
	} while (1);
	return (0);
}
