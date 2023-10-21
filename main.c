#include "monty.h"
stack_t *head = NULL;

/**
 * main - the starting point of the program
 * @argc: the total arguments provided including the filename
 * @argv: the array of strings of all the arguments
 * Return: 0(success)
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_open(argv[1]);
	free_node();
	return (0);
}

/**
 * create_node - a func that creates a new node
 * @nm: the int num to input in the node
 * Return: an address of the newnode
 */
stack_t *create_node(int nm)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		err(4);
	}
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->n = nm;
	return (new_node);
}

/**
 * push_to_queue - a func that adds a node to the queue structure
 * @new_node: an address to the new node
 * @ln_num: the line number of the opcode
 * Return: void(nothing)
 */
void push_to_queue(stack_t **new_node, __attribute__((unused))u
		nsigned int ln_num)
{
	stack_t *curr;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	curr = head;

	while (curr->next != NULL)
		curr = curr->next;

	curr->next = *new_node;
	(*new_node)->prev = curr;
}

/**
 * free_node - a func that frees a node space in the stack
 * Return: void (nothing)
 */
void free_node(void)
{
	stack_t *curr;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		curr = head;
		head = head->next;
		free(curr);
	}
}
