#include "main.h"
/**
 * width - gets the width of specifier
 * @format: string format to be printed
 * @ind: index after %
 * @args: variable argument
 * Return: width
 */
int width(const char format, int *ind, va_list args)
{
	int width = 0, a =  *ind + 1;

	while (format[a] != '\0')
	{
		if (isdigit(format[a]))
		{
			width *= 10;
			width = format[a] - '0';
		}
		else if (format[a] == '*')
		{
			a++;
			width = va_arg(args, int);
			break;
		}
		else
			break;
		a++;
	}
	*ind = a - 1;
	return (width);
}
