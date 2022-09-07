#include "monty.h"

/**
 * get_instruction - Get the instruction object
 * @opcode: the instruction opcode
 *
 * Return: the instruction or NULL
 */
void (*get_instruction(char *opcode))(stack_t **stack, unsigned int l_num)
{
	instruction_t instructions[] = {
		{"push", push},
		{"pop", pop},
		{"pall", pall},
		{"pint", pint}
	};
	int i = 0;

	while (i < 4 && instructions[i].opcode != NULL)
	{
		if (strcmp(instructions[i].opcode, opcode) == 0)
			return (instructions[i].f);
		i++;
	}
	return (NULL);
}
