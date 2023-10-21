#include "monty.h"

/**
 * err - a func that prints an error meassage by their error code
 * @err_code: the error codes (1,2,3,4,5,6,7,8)
 * Description: 1(no file) 2(file cant be opened) 3(invalid instruct)
 * 4(unable to malloc more memory) 5(when the arg is not int)
 * 6(when stack empty pint) 7(when stack empty for pop)
 * 8(when stakc too short) 9(div by 0) 10(when num is out of range in ascii)
 * 11(when stak is empty)
 * Return: void(nothing)
 */
void err(int err_code, ...)
{
	va_list ags;
	char *opc;
	int ln_num;

	va_start(ags, err_code);
	switch (err_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(ags, char *));
			break;
		case 3:
			ln_num = va_arg(ags, int);
			opc = va_arg(ags, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", ln_num, opc);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(ags, int));
			break;
		default:
			break;
	}

}

/**
 * err_handler - a func that handles the remaining errors
 * @err_code: the error number from(6,7,8,9)
 * Return: void(nothing)
 */
void err_handler(int err_code, ...)
{
	va_list ags;
	char *opc;
	int ln_num;

	va_start(ags, err_code);
	switch (err_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(ags, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(ags, int));
			break;
		case 8:
			ln_num = va_arg(ags, unsigned int);
			opc = va_arg(ags, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", ln_num, opc);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(ags, unsigned int));
			break;
		default:
			break;
	}
	free_node();
	exit(EXIT_FAILURE);
}

/**
 * str_err - a func that handles the string errr
 * @err_code: the err codes nums
 * Return: void(nothing)
 */
void str_err(int err_code, ...)
{
	va_list ags;
	int ln_numb;

	va_start(ags, err_code);
	ln_numb = va_arg(ags, int);

	switch (err_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", ln_numb);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", ln_numb);
			break;
		default:
			break;
	}

	free_node();
	exit(EXIT_FAILURE);
}
