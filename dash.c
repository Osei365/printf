#include "main.h"

/**
 * print_non_printable - print ASCII in hexa
 * for non printable characters
 * @types: arguments list
 * @buffer: array used to handle print
 * @width: width
 * @flags: give active flags
 * @precision: specify precision
 * @size: specify size
 *
 * Return: number of printed chars
 */
int print_non_printable(va_list args, char buf[],
	int flag, int width, int precision, int size)
{
	int a = 0;
	int offset = 0;
	int spaces = 0;
	char *str = va_arg(types, char *);

	(void)(flag);
	(void)(width);
	(void)(precision);
	(void)(size);

	if (str == NULL)
	{
		return (write(1, "(NULL)", 6));
	}
	while (str[a] != '\0')
	{
		if (is_printable(str[a]))
		{
			buf[a + offset] = str[a];
		}
		else
		{
			offset += append_hexa_code(str[a], buf, a + offset);
		}
		a++;
	}

	spaces = width - (a + offset);

	if ((flag & 1) != 0)
	{
		write(1, buf, a + offset);
		write_spaces(spaces);
	}
	else
	{
		write_spaces(spaes);
		write(1, buffer, i + offset);
	}
	return (i + offset + spaces);
}

/**
 * write_spaces - add space
 * @n: number of spaces
 *
 * Return: nothing
 */
void write_spaces(int n)
{
	while (n > 0)
	{
		write(1, " ", 1);
		n--;
	}
}
