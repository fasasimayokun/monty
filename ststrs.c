#include "monty.h"

/**
 * display_char - a func that displays the ASCII value of the char
 * @stack: the pointer to the pointer leading to the top node
 * @ln_number: the int representing the line num of the opcode
 * Return: void(nothing)
 */
void display_char(stack_t **stack, unsigned int ln_number)
{
	int asc;

	if (stack == NULL || *stack == NULL)
	{
		str_err(11, ln_number);
	}

	asc = (*stack)->n;
	if (asc < 0 || asc > 127)
	{
		str_err(10, ln_number);
	}
	printf("%c\n", asc);
}


/**
 * display_str - a func that displays a string
 * @stack: the pointer to the pointer leading to the top node
 * @ln_num: the int representing the line num of the opcode
 * Return: void(nothing)
 */
void display_str(stack_t **stack, __attribute__((unused))unsigned int ln_num)
{
	int asc;
	stack_t *curr;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	curr = *stack;
	while (curr != NULL)
	{
		asc = curr->n;
		if (asc <= 0 || asc > 127)
		{
			break;
		}
		printf("%c", asc);
		curr = curr->next;
	}
	printf("\n");
}

/**
 * rotl - a func that rotates the 1st node of the stack to the bottom.
 * @stack: the pointer to a pointer leading to the topmost node of the stack
 * @ln_numb: the int representing the line num of the opcode
 * Return: void(nothing)
 */
void rotl(stack_t **stack, __attribute__((unused))unsigned int ln_numb)
{
	stack_t *curr;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		return;
	}

	curr = *stack;
	while (curr->next != NULL)
	{
		curr = curr->next;
	}

	curr->next = *stack;
	(*stack)->prev = curr;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

/**
 * rotr - a func that rotates the last node of the stack to the top.
 * @stack: the pointer to a pointer leading to the topmost node of the stack
 * @ln_numb: the int representing the line num of the opcode
 * Return: void(nothing)
 */
void rotr(stack_t **stack, __attribute__((unused))unsigned int ln_numb)
{
	stack_t *curr;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		return;
	}

	curr = *stack;
	while (curr->next != NULL)
	{
		curr = curr->next;
	}

	curr->next = *stack;
	curr->prev->next = NULL;
	curr->prev = NULL;
	(*stack)->prev = curr;
	(*stack) = curr;
}
