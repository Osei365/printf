#include "main.h"
/**
 * print_char - prints the character
 * @args: the variabe argument
 * @buf: the buffer
 * Return: printed char
 */
int print_char(va_list args, char buf[])
{
	char ch;
	int a = 0;

	ch = va_arg(args, int);
	buf[a++] = ch;
	buf[a] = '\0';
	return (write(1, &buf[0], 1));
}
/**
 * print_string - prints the string
 * @args: the variable argument
 * @buf: the buffer
 * Return: printed string
 */
int print_string(va_list args, char buf[])
{
	char *str;
	int l;

	(void)(buf);
	str = va_arg(args, char*);
	l = strlen(str);
	if (str == NULL)
	{
		str = "(nil)";
	}
	return (write(1, str, l));
}

/**
 * print_percentage - prints the percentage
 * @args: the variable argument
 * @buf: the buffer
 * Return: printed percentage
 */
int print_percentage(va_list args, char buf[])
{
	(void)(args);
	(void)(buf);
	return (write(1, "%%", 1));
}

/**
 * print_integers - prints integers
 * @args: the variable argument
 * @buf: the buffer
 * Return: printed integer
 */
int print_integer(va_list args, char buf[])
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

	while (ch > 0)
	{
		buf[a--] = (n % 10) + '0';
		n /= 10;
	}
	if (negative_bool == 1)
	{
		buf[a--] = '-';
	}
	a++;
	return (write(1, &buf[a], BUFF_SIZE - a - 1));
}
