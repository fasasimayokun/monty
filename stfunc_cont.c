#include "monty.h"

/**
 * nop - a func that does nothing
 * @stack: address to the pointer leading to the top node
 * @ln_num: the int representing the line num of the opcode
 * Return: void(nothing)
 */
void nop(stack_t **stack, unsigned int ln_num)
{
	(void)stack;
	(void)ln_num;
}

/**
 * swap_nodes - a func that swaps the top 2 elem of the stack
 * @stack: the pointer to the addrs leading to the top node
 * @ln_numb: the int representing the line num of opcode
 * Return: void(nothing)
 */
void swap_nodes(stack_t **stack, unsigned int ln_numb)
{
	stack_t *curr;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		err_handler(8, ln_numb, "swap");
	}
	curr = (*stack)->next;
	(*stack)->next = curr->next;
	if (curr->next != NULL)
	{
		curr->next->prev = *stack;
	}
	curr->next = *stack;
	(*stack)->prev = curr;
	curr->prev = NULL;
	*stack = curr;
}

/**
 * add_nodes - a func that adds the top 2 elems in the stack
 * @stack: the address to the address leading to the top node
 * @line_nm: the int representing the line num of the opcode
 * Return: void(nothing)
 */
void add_nodes(stack_t **stack, unsigned int line_nm)
{
	int add;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		err_handler(8, line_nm, "add");
	}

	(*stack) = (*stack)->next;
	add = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = add;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * subt_nodes - a func that sub the top 2 elems in stack
 * @stack: the pointer to the addrss leading to the top node
 * @ln_number: the int representing the line num of the opcode
 * Return: void(nothing)
 */
void subt_nodes(stack_t **stack, unsigned int ln_number)
{
	int sub;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		err_handler(8, ln_number, "sub");
	}

	(*stack) = (*stack)->next;
	sub = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sub;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * div_nodes - a func that div the top 2 elem of the stack
 * @stack: the address to the addresss leading to the top node
 * @line_nm: the int representing the line num of the opcode
 * Return: void(nothing)
 */
void div_nodes(stack_t **stack, unsigned int line_nm)
{
	int dv;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		err_handler(8, line_nm, "div");
	}

	if ((*stack)->n == 0)
	{
		err_handler(9, line_nm);
	}
	(*stack) = (*stack)->next;
	dv = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = dv;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
