#include "main.h"
/**
 * print_spec - prints specifier
 * @format: format string
 * @i: index in format string
 * @args: variable argument at i
 * @buf: buffer
 * Return: printed characters else -1
 */
int print_spec(const char *format, int *i, va_list args, char buf[])
{
	int chars_num = -1, a, add_len = 0;
	sp_f specifiers[] = {
		{'c', print_char}, {'%', print_percentage}, {'s', print_string},
		{'d', print_integer}, {'i', print_integer}, {'\0', NULL}
	};

	for (a = 0; specifiers[a].sp != '\0'; a++)
	{
		if (format[*i] == specifiers[a].sp)
			return (specifiers[a].func(args, buf));
	}
	if (specifiers[a].sp == '\0')
	{
		if (format[*i] == '\0')
			return (-1);
		add_len += write(1, &format[*i], 1);
		return (add_len);
	}
	return (chars_num);
}
