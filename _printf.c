#include "main.h"

void write_buffer(char buf[], int *b_ind);
int print_string(va_list args);
int print_char(va_list args);

/**
 * _printf - prints string literals
 * @format: contains character string to be printed
 * Return: numbers of characters
 */
int _printf(const char *format, ...)
{
	va_list args;
	int a, chars_count = 0, b_ind = 0, spec_count = 0;
	char buff[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (a = 0; format && format[a] != '\0'; a++)
	{
		if (format[a] != '%')
		{
			buff[b_ind++] = format[a];
			if (b_ind == BUFF_SIZE)
				write_buffer(buff, &b_ind);
			chars_count++;
		}
		else
		{
			write_buffer(buff, &b_ind);
			a++;
			if (format[a] == 'c')
				spec_count = print_char(args);
			else if (format[a] == 's')
				spec_count = print_string(args);
			else if (format[a] == '%')
				spec_count = write(1, "%%", 1);
			if (spec_count == -1)
				return (-1);
			chars_count += spec_count;
		}
	}
	write_buffer(buff, &b_ind);
	va_end(args);
	return (chars_count);
}

void write_buffer(char buf[], int *b_ind)
{
	if (*b_ind > 0)
		write(1, &buf[0], *b_ind);
	*b_ind = 0;
}

int print_string(va_list args)
{
	char *str;
	int l;

	str = va_arg(args, char*);
	l = strlen(str);
	if (str == NULL)
	{
		str = "(nil)";
	}
	return (write(1, str, l));
}
int print_char(va_list args)
{
	char ch;
	char buf[2];
	int a = 0;

	ch = va_arg(args, int);
	buf[a++] = ch;
	buf[a] = '\0';
	return (write(1, &buf[0], 1));
}
