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

/**
 * add_node_end - adds a node a the end of a doubly linked list
 * @head: pointer to head of the doubly linked list
 * @val: data to be added
 */
void add_node_end(stack_t **head, const int val)
{
	stack_t *node, *temp;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		malloc_error();

	node->n = val;
	node->prev = NULL;
	node->next = NULL;

	if (*head == NULL)
		*head = node;
	else
	{
		temp = *head;
		while (temp->next != NULL)
			temp = temp->next;

		temp->next = node;
		node->prev = temp;
	}
}

/**
 * delete_node_end - deletes a node from the end of a doubly linked list
 * @head: pointer to head of the doubly linked list
 */
void delete_node_end(stack_t **head)
{
	stack_t *temp;

	if (*head != NULL)
	{
		temp = *head;
		while (temp->next != NULL)
			temp = temp->next;

		if (temp->prev == NULL)
			*head = NULL;
		else
			temp->prev->next = NULL;

		free(temp);
	}
}
