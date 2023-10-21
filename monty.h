#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
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
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void(*op_func)(stack_t **, unsigned int);

void find_func(char *, char *, int, int);
void file_open(char *file_name);
void flread(FILE *);
int len_of_chars(FILE *);
int parseLine(char *buff, int ln_num, int format);

stack_t *create_node(int nm);
void push_to_stack(stack_t **, unsigned int);
void push_to_queue(stack_t **, unsigned int);
void free_node(void);
void display_stack(stack_t **, unsigned int);
void display_top(stack_t **, unsigned int);
void pop_top(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void call_func(op_func, char *, char *, int, int);
void swap_nodes(stack_t **, unsigned int);

void add_nodes(stack_t **, unsigned int);
void div_nodes(stack_t **, unsigned int);
void modul_nodes(stack_t **, unsigned int);
void mult_nodes(stack_t **, unsigned int);
void subt_nodes(stack_t **, unsigned int);

void display_char(stack_t **, unsigned int);
void display_str(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);

void err(int err_code, ...);
void err_handler(int err_code, ...);
void str_err(int err_code, ...);
void rotr(stack_t **, unsigned int);

#endif
