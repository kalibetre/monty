#ifndef MONTY_H
#define MONTY_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void interpret_file(char *filename);
int _getline(char **line, size_t *line_n, int fd);
int isnumber(char *str);

/*Stack*/
stack_t *push_node(stack_t **stack, const int n);
stack_t *pop_node(stack_t **stack);
void free_stack(stack_t *stack);

/*Instructions*/
void (*get_instruction(char *opcode))(stack_t **, unsigned int);
void pop(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);

/*Error Messages*/
void invalid_argument(void);
void failed_to_open_file(char *filename);
void invalid_instruction(int line_number, char *opcode);
void malloc_error(void);
void invalid_int_arg(int line_number);

#endif
