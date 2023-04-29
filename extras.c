#include "main.h"

/**
 * is_printable - checks if char is printable
 * @ch: Char
 *
 * Return: 1 or 0
 */
int is_printable(char ch)
{
	if (ch >= 32 && ch < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - Append ascii in base16 code to buffer
 * @buf: Array of chars.
 * @ind: Index
 * @ascii_code: ASCII CODE.
 *
 * Return: 3
 */
int append_hexa_code(char ascii_code, char buf[], int ind)
{
	char map[] = "0123456789ABCDEF";
	if (ascii_code < 0)
		ascii_code *= -1;

	buf[ind++] = '\\';
	buf[ind++] = 'x';

	buf[ind++] = map[ascii_code / 16];
	buf[ind] = map[ascii_code % 16];

	return (3);
}

/**
 * is_digit - checks if a character is
 * a digit
 * @ch: Char to be evaluated
 *
 * Return: 1 or 0
 */
int is_digit(char ch)
{
	if (ch >= '0' && ch <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - converts number to indicated size
 * @n: Number
 * @size: size
 *
 * Return: converted value
 */
long int convert_size_number(long int n, int size)
{
	if (size == 2)
		return (n);
	else if (size == 1)
		return ((short)n);

	return ((int)n);
}

/**
 * convert_size_unsgnd - converts to given size
 * @n: Number
 * @size: size
 *
 * Return: converted number
 */
long int convert_size_unsgnd(unsigned long int n, int size)
{
	if (size == 2)
		return (n);
	else if (size == 1)
		return ((unsigned short)n);

	return ((unsigned int)n);
}
