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
int print_char(va_list args, char buf[], int flag, int width, int precision, int size);
int print_string(va_list args, char buf[], int flag, int width, int precision, int size);
int print_percentage(va_list args, char buf[], int flag, int width, int precision, int size);
int print_integer(va_list args, char buf[], int flag, int width, int precision, int size);
int print_spec(const char *format, int *i, va_list args, char buf[], int flag, int width, int precision, int size);
int write_char(char ch, char buf[], int precision, int width, int flag, int size);
int write_int(int negative_bool, int ind, char buf[], int precision, int width, int size, int flag);
int write_integer(int ind, char buf[], int precision, int width, int flag, int l, char ch, char padding);
int write_unsigned(int negative_bool, int ind, char buf[], int flag, int width, int precision, int size);



int size(const char format, int *ind);
int flags(const char format, int *ind);
int width(const char format, int *ind, va_list args);
int precision(const char format, int *ind, va_list args);
#endif
