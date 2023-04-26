#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#define BUFF_SIZE 1024
/**
 * struct function_specifiers - the specifiers structure
 * @sp: specifier
 * @func: specifier function
 *
 * Description: Longer description
 */
struct function_specifiers
{
	char sp;
	int (*func)(va_list, char[], int, int, int, int);
};
/**
 * sp_f - Typedef for struct function_specifiers
 */
typedef struct function_specifiers sp_f;
int _printf(const char *format, ...);
#endif
