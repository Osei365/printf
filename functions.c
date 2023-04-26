#include "main.h"
/**
 * print_char - prints the character
 * @args: the variabe argument
 * @buf: the buffer
 * @flag: flag
 * @width: width
 * @precision: precision
 * @size: size
 * Return: printed char
 */
int print_char(va_list args, char buf[], int flag, int width,
		int precision, int size)
{
	char ch;

	ch = va_arg(args, int);
	return (write_char(ch, buf, precision, width, flag, size));
}
/**
 * print_string - prints the string
 * @args: the variable argument
 * @buf: the buffer
 * @flag: flag
 * @width: width
 * @precision: precision
 * @size: size
 * Return: printed string
 */
int print_string(va_list args, char buf[], int flag, int width,
		int precision, int size)
{
	char *str;
	int l, a;

	(void)(buf);
	(void)(flag);
	(void)(width);
	(void)(precision);
	(void)(size);
	str = va_arg(args, char*);
	l = strlen(str);
	if (str == NULL)
	{
		str = "(nil)";
		if (precision >= 6)
			str = "      ";
	}
	if (precision > 0 && precision < l)
		l = precision;
	if (width > l)
	{
		if (flag & 1)
		{
			write(1, &str[0], l);
			for (a = width - l; a > 0; a--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (a = width - l; a > 0; a--)
				write(1, " ", 1);
			write(1, &str[0], l);
			return(width);
		}
	return (write(1, str, l));
}

/**
 * print_percentage - prints the percentage
 * @args: the variable argument
 * @buf: the buffer
 * @flag: flag
 * @width: width
 * @precision: precision
 * @size: size
 * Return: printed percentage
 */
int print_percentage(va_list args, char buf[], int flag, int width,
		int precision, int size)
{
	(void)(args);
	(void)(buf);
	(void)(flag);
	(void)(width);
	(void)(precision);
	(void)(size);
	return (write(1, "%%", 1));
}

/**
 * print_integers - prints integers
 * @args: the variable argument
 * @buf: the buffer
 * @flag: flag
 * @width: width
 * @precision: precision
 * @size: size
 * Return: printed integer
 */
int print_integer(va_list args, char buf[], int flag, int width,
		int precision, int size)
{
	int a = BUFF_SIZE - 2;
	long int ch = va_arg(args, long int);
	unsigned long int n;
	int negative_bool = 0;

	if (ch == 0)
	{
		buf[a--] = '0';
	}

	buf[BUFF_SIZE - 1] = '\0';
	n = (unsigned long int)ch;
	if (ch < 0)
	{
		n = (unsigned long int)(-1 * ch);
		negative_bool = 1;
	}

	while (n > 0)
	{
		buf[a--] = (n % 10) + '0';
		n /= 10;
	}
	a++;
	return (write_int(negative_bool, a, buf, precision, width, size, flag));
}
