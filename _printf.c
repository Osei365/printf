#include "main.h"

void write_buffer(char buf[], int *b_ind);

/**
 * _printf - prints string literals
 * @format: contains character string to be printed
 * Return: numbers of characters
 */
int _printf(const char *format, ...)
{
	va_list args;
	int a, chars_count = 0, b_ind = 0, spec_count = 0;
	int flags, width, precision, size;
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
			flags = calc_flags(format, &a);
			size = calc_size(format, &a);
			precision = calc_precision(format, &a, args);
			width = calc_width(format, &a, args);
			a++;
			spec_count = print_spec(format, &a, args, buff,
					flags, width, precision, size);
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
