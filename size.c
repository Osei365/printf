#include "main.h"
/**
 * size - get the size of specifier
 * @format: string to print
 * @ind: index in format
 * Return: size
 */
int size(const char format, int *ind)
{
	int sz = 0, a = *ind + 1;

	if (format[a] == 'l')
		sz = 2;
	else if (format[a] == 'h')
		sz = 1;
	
	if (sz == 0)
		*ind = a - 1;
	else
		*ind = a;

	return (sz);
}
