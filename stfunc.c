#include "monty.h"

/**
 * push_to_stack - a func that adds a node to the stack data structure
 * @new_node: the addrs to the new node
 * @ln_num: the int representing the line number of the opcode
 * Return: void(nothing)
 */
void push_to_stack(stack_t **new_node, __attribute__((unused))
		unsigned int ln_num)
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
	head = *new_node;
	head->next = curr;
	curr->prev = head;
}

/**
 * display_stack - a func that prints the elems in the stack
 * @stack: an address to the address pointing the top node
 * @ln_num: the line num of the opcode
 * Return: void(nothing)
 */
void display_stack(stack_t **stack, unsigned int ln_num)
{
	stack_t *curr;

	(void) ln_num;
	if (stack == NULL)
	{
		exit(EXIT_FAILURE);
	}
	curr = *stack;
	while (curr != NULL)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
}

/**
 * pop_top - a func that pop the top node of the stack
 * @stack: the address to the address of the top node
 * @ln_num: the int representing the line num of the opcode
 * Return: void(nothing)
 */
void pop_top(stack_t **stack, unsigned int ln_num)
{
	stack_t *curr;

	if (stack == NULL || *stack == NULL)
	{
		err_handler(7, ln_num);
	}

	curr = *stack;
	*stack = curr->next;
	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
	free(curr);
}

/**
 * display_top - a func that prints the top node
 * @stack: the addrss to the addres pointing to the top node
 * @ln_num: the int representing the line num of the opcode
 * Return: void(nothing)
 */
void display_top(stack_t **stack, unsigned int ln_num)
{
	if (stack == NULL || *stack == NULL)
	{
		err_handler(6, ln_num);
	}
	printf("%d\n", (*stack)->n);
}
