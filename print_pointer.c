#include "main.h"

/**
 * print_pointer - Prints a pointer variable
 * @args: variable argument
 * @buf: Buffer
 * @flags:  flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: count of chars printed.
 */
int print_pointer(va_list args, char buf[],
	int flags, int width, int precision, int size)
{
	char ch = 0, padding = ' ';
	int i = BUFF_SIZE - 2, l = 2, padding_st = 1;
	unsigned long num_ptrs;
	char map[] = "0123456789abcdef";
	void *ptrs = va_arg(args, void *);

	(void)(width);
	(void)(size);

	if (ptrs == NULL)
		return (write(1, "(nil)", 5));

	buf[BUFF_SIZE - 1] = '\0';
	(void)(precision);

	num_ptrs = (unsigned long)ptrs;

	for (; num_ptrs > 0; num_ptrs /= 16, l++)
	{
		buf[i--] = map[num_ptrs % 16];
	}

	if ((flags & 4) && !(flags & 1))
		padding = '0';
	if (flags & 2)
	{
		ch = '+';
		l++;
	}
	else if (flags & 16)
	{
		ch = ' ';
		l++;
	}
	i++;
	return (write_pointer(buf, i, l,
		width, flags, padding, ch, padding_st));
}
