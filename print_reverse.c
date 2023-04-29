#include "main.h"

/**
 * print_reverse - print string in reverse
 * @types: arguments list
 * @buffer: array used to handle print
 * @width: width
 * @flags: give active flags
 * @precision: specify precision
 * @size: specify size
 *
 * Return: number of printed chars
 */
int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int i;
	int count = 0;

	(void)(buffer);
	(void)(width);
	(void)(flags);
	(void)(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		(void)(precision);
		str = "(Null)";
	}
	for (i = 0; str[i]; i++)
	{
		;
	}
	for (i = i - 1; i >= 0; i--)
	{
		char k = str[i];

		write(1, &k, 1);
		count++;
	}
	return (count);
}
