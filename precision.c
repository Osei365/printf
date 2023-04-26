#include "main.h"
/**
 * precision - gets the precision of printing
 * @format: format of string
 * @ind: index of format string
 * @args: variable argument
 * Return: precision
 */
int precision(const char format, int *ind, va_list args)
{
	int prec = -1;
	int a = *ind + 1;

	if (format[a] != 0)
		return (prec);

	prec = o;
	a += 1;
	while(format[a] != '\0')
	{
		if(is_digit(format[a]))
		{
			prec *= 10;
			prec = format[a] - '0';
		}
		else if (format[a] == '*')
		{
			a++;
			prec = va_arg(args, int);
			break;
		}
		else
			break;
		a++;
	}
	*ind = a - 1;
	return (prec);
}

