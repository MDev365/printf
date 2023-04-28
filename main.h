#ifndef MAIN_H
#define MAIN_H

/* flags - flags struct
 * @plus: +
 * @space: ' '
 * @hash: #
 */
typedef struct flags{
	int plus;
	int space;
	int hash;
} flags_ty;

/* std libs */
#include <stdarg.h>
#include <stdlib.h>

/* putchar and print functions */
int _putchar(char c);
int print_address(void *p);
int print_string_non_print(char *s);
int print_reverse_string(char *s);
int print_rot13ed_string(char *s);
int print_string(char *s);

/* conversions functions */
int _strlen(const char *s);
int int_to_string(int num, char *buf);
int int_to_binary(unsigned int num, char *buf);
int int_to_octal(unsigned int num, char *buf);
int int_to_hex(unsigned int num, char *buf, int cap);
int uint_to_string(unsigned int num, char *buf);

/* get functions */
int get_flags(const char *s, flags_ty *flags);
int get_width(const char *s, int *width, va_list args);
int get_precision(const char *s, int *precision, va_list args);
int get_length_modifier(const char *s, char *length);

int _printf(const char *format, ...);
#endif
