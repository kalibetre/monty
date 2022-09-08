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

/**
 * struct app_state_s - representation of the app state
 * @file_d: the file descriptor
 * @line_buff: the recent line read from input
 * @stack: app stack
 *
 * Description: a struct to hold the current app state
 */
typedef struct app_state_s
{
	int file_d;
	char *line_buff;
	stack_t *stack;
} app_state_t;

extern app_state_t app_state;

void free_app_state(void);

void interpret_file(void);
int _getline(char **line, size_t *line_n, int fd);
int isnumber(char *str);

/*Stack*/
stack_t *push_node(stack_t **stack, const int n);
stack_t *pop_node(stack_t **stack);
void free_stack(stack_t *stack);

/*Instructions*/
void (*get_instruction(char *opcode, int l_num))(stack_t **, unsigned int);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);

/*Error Messages*/
void invalid_argument(void);
void failed_to_open_file(char *filename);
void invalid_instruction(int line_number, char *opcode);
void malloc_error(void);
void invalid_int_arg(int line_number);
void pop_error(int l_num);
void failed_to_read_line(void);
void stack_to_short_error(const char *msg, int l_num);
void stack_empty_error(char *msg, int l_num);
void div_by_zero_error(int l_num);
void ascii_error(int l_num);

#endif
