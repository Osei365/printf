#include "main.h"
/**
 * flags: gets the flags for non
 * conversion specifiers
 * @format: format string
 * @ind: index position
 * Return: flag
 */
int flags(const char format, int *ind)
{
	int a = *ind + 1, b, flag = 0;
	const char flag_chars[] = {'+', ' ', '#', '0', '-', '\0'};
	const int flag_conv[] = {2, 16, 8, 4, 1, 0};

	while(format[a] != '\0')
	{
		for (b = 0; flag_chars[b] != '\0', b++)
		{
			if (format[a] == flag_chars[b])
			{
				flag = flag | flag_conv[b];
				break;
			}
		}
		if (flag_chars[b] == 0)
			break;

		a++;
	}

	*ind = a - 1;
	return (flag);
}
