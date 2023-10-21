#include "monty.h"
/**
 * modul_nodes - a func that finds the modulus of the top 2 elems in the stakc
 * @stack: the pointer to a pointer leading to the top node
 * @line_numb: the int representing the line num of the opcode
 * Return: void(nothing)
 */
void modul_nodes(stack_t **stack, unsigned int line_numb)
{
	int mod;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		err_handler(8, line_numb, "mod");
	}

	if ((*stack)->n == 0)
	{
		err_handler(9, line_numb);
	}
	(*stack) = (*stack)->next;
	mod = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = mod;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 * mult_nodes - a func that multiples the top 2 elems o a stack
 * @stack: pointer to a pointer leadingi to the top node
 * @ln_num: the int representing the line num of the opcode
 * Return: void(nothing)
 */
void mult_nodes(stack_t **stack, unsigned int ln_num)
{
	int mul;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		err_handler(8, ln_num, "mul");
	}

	(*stack) = (*stack)->next;
	mul = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = mul;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
