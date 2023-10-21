#include "monty.h"

/**
 * file_open - a func that opens a file
 * @file_name: the file path
 * Return: void (nothing)
 */
void file_open(char *file_name)
{
	FILE *fd = fopen(file_name, "r");

	if (file_name == NULL || fd == NULL)
		err(2, file_name);

	flread(fd);
	fclose(fd);
}

/**
 * flread - a func that reads a file
 * @fd: an address to the file descriptor
 * Return: void(nothing)
 */
void flread(FILE *fd)
{
	int line_number, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (line_number = 1; getline(&buffer, &len, fd) != -1; line_number++)
	{
		format = parseLine(buffer, line_number, format);
	}
	free(buffer);
}

/**
 * parseLine - a func that separates each line into words
 * to know which func to be called
 * @buff: the line from the file
 * @ln_num: the line num
 * @format: the storage format 1(queue) 0(stack)
 * Return: 0 if (opcode is stack) else 1(queue)
 */
int parseLine(char *buff, int ln_num, int format)
{
	char *opcode;
	char *val;
	const char *delim = "\n";

	if (buff == NULL)
		err(4);

	opcode = strtok(buff, delim);
	if (opcode == NULL)
		return (format);
	val = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
	{
		return (0);
	}
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_func(opcode, val, ln_num, format);
	return (format);
}

/**
 * find_func - a func that finds the func for the opcode
 * @opcode: the opcode number
 * @val: the val of the opcode
 * @format: the storage format either stack or queue (0 or 1)
 * @ln_num: the line num
 * Return: void(nothing)
 */
void find_func(char *opcode, char *val, int ln_num, int format)
{
	int nm;
	int fg;

	instruction_t func_arr[] = {
		{"push", push_to_stack},
		{"pall", display_stack},
		{"pint", display_top},
		{"pop", pop_top},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{"sub", subt_nodes},
		{"div", div_nodes},
		{"mul", mult_nodes},
		{"mod", modul_nodes},
		{"pchar", display_char},
		{"pstr", display_str},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};
	if (opcode[0] == '#')
		return;

	for (fg = 1, nm = 0; func_arr[nm].opcode != NULL; nm++)
	{
		if (strcmp(opcode, func_arr[nm].opcode) == 0)
		{
			call_func(func_arr[nm].f, opcode, val, ln_num, format);
			fg = 0;
		}
	}
	if (fg == 1)
		err(3, ln_num, opcode);
}

/**
 * call_func - a func that call the function required
 * @func: the address to the func to be called
 * @op: the str representations of the opcode
 * @val: the str representaions of the numeric value
 * @ln_num: the line num for the instruction
 * @format: the format specifier either stack or queue (0 or 1)
 * Return: void(nothing)
 */
void call_func(op_func func, char *op, char *val, int ln_num, int format)
{
	stack_t *newnode;
	int nm;
	int flag;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
		{
			err(5, ln_num);
		}
		for (nm = 0; val[nm] != '\0'; nm++)
		{
			if (isdigit(val[nm] == 0))
				err(5, ln_num);
		}

		newnode = create_node(atoi(val) * flag);
		if (format == 0)
		{
			func(&newnode, ln_num);
		}
		if (format == 1)
			push_to_queue(&newnode, ln_num);
	}
	else
	{
		func(&head, ln_num);
	}
}
