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
int print_binary(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_unsigned(va_list args, char buf[],
	int flags, int width, int precision, int size);
int print_base8(va_list args, char buf[],
	int flags, int width, int precision, int size);
int print_base16(va_list args, char buf[],
	int flags, int width, int precision, int size);
int print_upper_base16(va_list args, char buf[],
	int flags, int width, int precision, int size);
int print_16(va_list args, char map[], char buf[],
	int flags, char spec, int width, int precision, int size);
int print_pointer(va_list args, char buf[],
	int flags, int width, int precision, int size);
int write_pointer(char buf[], int i, int l,
	int width, int flags, char padding, char ch, int padding_st);

int write_char(char ch, char buf[], int precision, int width, int flag, int size);
int write_int(int negative_bool, int ind, char buf[], int precision, int width, int size, int flag);
int write_integer(int ind, char buf[], int precision, int width, int flag, int l, char ch, char padding);
int write_unsigned(int negative_bool, int ind, char buf[], int flag, int width, int precision, int size);

int print_rot13string(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_reverse(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_non_printable(va_list args, char buf[], int flag, int width, int precision, int size);
int calc_size(const char *format, int *ind);
int calc_flags(const char *format, int *ind);
int calc_width(const char *format, int *ind, va_list args);
int calc_precision(const char *format, int *ind, va_list args);

int is_printable(char ch);
int append_hexa_code(char ascii_code, char buf[], int ind);
int is_digit(char ch);
long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);
#endif
