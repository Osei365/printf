#include "main.h"


/**
 * print_unsigned - Prints an unsigned number
 * @args: variable argument
 * @buf: buffer
 * @flags:  flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: character count that was printed
 */
int print_unsigned(va_list args, char buf[],
	int flags, int width, int precision, int size)
{
	int a = BUFF_SIZE - 2;
	unsigned long int n = va_arg(args, unsigned long int);

	n = convert_size_unsgnd(n, size);

	if (n == 0)
		buf[a--] = '0';

	buf[BUFF_SIZE - 1] = '\0';

	for (; n > 0; n = n / 10)
	{
		buf[a--] = (n % 10) + '0';
	}

	a++;

	return (write_unsigned(0, a, buf, flags, width, precision, size));
}


/**
 * print_base8 - Prints unsigned int in base 8
 * @args: variable argument
 * @buf: Buffer
 * @flags: flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: count of chars printed
 */
int print_base8(va_list args, char buf[],
	int flags, int width, int precision, int size)
{

	int a = BUFF_SIZE - 2;
	unsigned long int n = va_arg(args, unsigned long int);
	unsigned long int init = n;

	(void)(width);

	n = convert_size_unsgnd(n, size);

	if (n == 0)
		buf[a--] = '0';

	buf[BUFF_SIZE - 1] = '\0';

	for (; n > 0; n /= 8)
	{
		buf[a--] = (n % 8) + '0';
	}

	if (flags & 8 && init != 0)
		buf[a--] = '0';

	a++;

	return (write_unsigned(0, a, buf, flags, width, precision, size));
}


/**
 * print_base16 - Prints unsigned int in base 16
 * @args: variable argument
 * @buf: Buffer
 * @flags:  flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: count of chars printed
 */
int print_base16(va_list args, char buf[],
	int flags, int width, int precision, int size)
{
	return (print_16(args, "0123456789abcdef", buf,
		flags, 'x', width, precision, size));
}


/**
 * print_upper_base16 - Prints base 16 in uppercase
 * @args: variable argument
 * @buf: Buffer
 * @flags:  flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * Return: Count of chars printed
 */
int print_upper_base16(va_list args, char buf[],
	int flags, int width, int precision, int size)
{
	return (print_16(args, "0123456789ABCDEF", buf,
		flags, 'X', width, precision, size));
}


/**
 * print_16 - multipurpose print for base 16 int 
 * @args: variable argument
 * @map: map values in array
 * @buf: Buffer
 * @flags: flags
 * @spec: flags
 * @width: width
 * @precision: Precision
 * @size: Size
 * @size: Size
 * Return: count of chars printed
 */
int print_16(va_list args, char map[], char buf[],
	int flags, char spec, int width, int precision, int size)
{
	int a = BUFF_SIZE - 2;
	unsigned long int n = va_arg(args, unsigned long int);
	unsigned long int init = n;

	(void)(width);

	n = convert_size_unsgnd(n, size);

	if (n == 0)
		buf[a--] = '0';

	buf[BUFF_SIZE - 1] = '\0';

	for (; n > 0; n /= 16)
	{
		buf[a--] = map[n % 16];
	}

	if (flags & 8 && init != 0)
	{
		buf[a--] = spec;
		buf[a--] = '0';
	}

	a++;

	return (write_unsigned(0, a, buf, flags, width, precision, size));
}
