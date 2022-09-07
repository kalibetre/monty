#include "monty.h"

/**
 * isnumber - checks if a string is a valid number
 * @str: the string
 *
 * Return: 1 if it is a valid number or 0
 */
int isnumber(char *str)
{
	size_t i = 0;

	if (str[i] == '-')
		i++;

	for (; i < strlen(str); i++)
	{
		if (str[i] >= 48 && str[i] <= 57)
			continue;
		return (0);
	}
	return (1);
}
