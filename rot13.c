#include "main.h"

/**
 * print_rot13string - print a string in rot13
 * @types: arguments list
 * @buffer: array used to handle print
 * @width: width
 * @flags: give active flags
 * @precision: specify precision
 * @size: specify size
 *
 * Return: number of printed chars
 */
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char x;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxtzabcdefghijklm";
	char *str;
	int count = 0;
	unsigned int i, j;

	str = va_arg(types, char*);
	UNUSED(buffer);
	UNUSED(width);
	UNUSED(flags);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
	{
		str = "(AHYY)";
	}
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
