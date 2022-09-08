#include "monty.h"

/**
 * add_node_front - adds a node a the beginning of a doubly linked list
 * @head: pointer to head of the doubly linked list
 * @val: data to be added
 */
void add_node_front(stack_t **head, const int val)
{
	stack_t *node;
	
	node = malloc(sizeof(stack_t));
	if (node == NULL)
		malloc_error();

	node->n = val;
	node->prev = NULL;
	node->next = NULL;
	if (*head != NULL)
	{
		(*head)->prev = node;
		node->next = *head;
	}
	*head = node;
}

/**
 * delete_node_front - removes node from beginning of a doubly linked list
 * @head: pointer to head of the doubly linked
 */
void delete_node_front(stack_t **head)
{
	stack_t *node;

	node = *head;
	*head = node->next;
	if (*head != NULL)
		(*head)->prev = NULL;
	free(node);
}
