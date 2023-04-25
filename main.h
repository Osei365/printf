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
	int (*func)(va_list, char[]);
};
/**
 * sp_f - Typedef for struct function_specifiers
 */
typedef struct function_specifiers sp_f;
int _printf(const char *format, ...);
int print_char(va_list args, char buf[]);
int print_string(va_list args, char buf[]);
int print_percentage(va_list args, char buf[]);
int print_integer(va_list args, char buf[]);
int print_spec(const char *format, int *i, va_list args, char buf[]); 

#endif
