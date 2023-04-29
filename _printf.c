#include "main.h"
#include <stdio.h>

/**
 * extract_conversion_specification - extract_conversion_specification
 * @format: format
 * @flags: flags
 * @width: width
 * @precision: precision
 * @args: args
 *
 * Return: int length
*/
int extract_conversion_specification(const char *format, flags_ty *flags,
				      int *width, int *precision, va_list args)
{
	int i = 0;

	i += get_flags(&format[i + 1], flags);
	i += get_width(&format[i + 1], width, args);
	i += get_precision(&format[i + 1], precision, args);
	i += get_length_modifier(&format[i + 1], flags);
	i += get_conversion_specifier(&format[i + 1], flags);

	return (i);
}

/**
 * extract_conversion_specification - extract_conversion_specification
 * @flags: flags
 * @width: width
 * @precision: precision
 * @args: args
 *
 * Return: int length
*/
int handle_int_specifiers(flags_ty *flags,
				      int width, int precision, va_list args)
{
	int len = 0;
	char int_buf[40], binary_buf[40];

	binary_buf[0] = '\0';
	if (flags->specifier == 'i' || flags->specifier == 'd')
	{
		int_to_string(va_arg(args, int), int_buf, flags, precision);
		len += print_numeric(int_buf, width, precision, flags);
	}
	else if (flags->specifier == 'b')
	{
		binary_buf[0] = '\0';
		int_to_binary(va_arg(args, unsigned int), binary_buf, flags);
		len += print_numeric(binary_buf, width, precision, flags);
	}
	else if (flags->specifier == 'o')
	{
		int_to_octal(va_arg(args, unsigned int), binary_buf, flags);
		len += print_numeric(binary_buf, width, precision, flags);
	}
	else if (flags->specifier == 'u')
	{
		uint_to_string(va_arg(args, unsigned int), binary_buf, flags);
		len += print_numeric(binary_buf, width, precision, flags);
	}
	else if (flags->specifier == 'x')
	{
		int_to_hex(va_arg(args, unsigned int), binary_buf, 0, flags);
		len += print_numeric(binary_buf, width, precision, flags);
	}
	else if (flags->specifier == 'X')
	{
		int_to_hex(va_arg(args, unsigned int), binary_buf, 1, flags);
		len += print_numeric(binary_buf, width, precision, flags);
	}
	return (len);
}



/**
 * handle_conversion_specification - handle_conversion_specification
 * @format: format
 * @args: args
 * @ind: index
 * @conv_len: conversion length
 * Return: int length
*/
int handle_conversion_specification(const char *format, va_list args,
									int *ind, int *conv_len)
{
	int i = *ind, width = 0, precision = -1, len = 0, conv_exist = 1;
	flags_ty flags = {0, 0, 0, 0, 0, 0, 0};

	i += extract_conversion_specification(&format[i], &flags, &width,
					       &precision, args);
	if (flags.specifier == 'c')
	{
		len += print_char(va_arg(args, int), width, &flags);
	}
	else if (flags.specifier == 's')
		len += print_string(va_arg(args, char *), width, precision, &flags);
	else if (flags.specifier == 'S')
		len += print_string_non_print(va_arg(args, char *));
	else if (flags.specifier == '%')
	{
		_putchar('%');
		len++;
	}
	else if (flags.specifier == 'i' || flags.specifier == 'd' ||
		 flags.specifier == 'o' || flags.specifier == 'u' ||
		 flags.specifier == 'x' || flags.specifier == 'X')
		len += handle_int_specifiers(&flags,
					       width, precision, args);
	else if (flags.specifier == 'p')
		len += print_address(va_arg(args, void *));
	else if (flags.specifier == 'r')
		len += print_reverse_string(va_arg(args, char *));
	else if (flags.specifier == 'R')
		len += print_rot13ed_string(va_arg(args, char *));
	else
		conv_exist = 0;

	*ind = i;
	*conv_len = len;

	if (flags.specifier != 0)
		conv_exist = 1;
	return (conv_exist);
}

/**
 * _printf - printf replica
 * @format: format
 *
 * Return: lenght of the string printed
 */
int _printf(const char *format, ...)
{
	int i, i_before, len = 0, buf_idx, conv_len = 0, conv_exist;
	va_list args;
	char buf[1024];

	va_start(args, format);
	/*not used variabled*/
	(void)buf;
	(void)buf_idx;

	if (format == NULL)
		return (-1);
	for (i = 0 ; format[i] != '\0' ; i++)
	{
		if (format[i] == '%')
		{
			i_before = i;
			conv_exist = handle_conversion_specification(format, args, &i, &conv_len);
			len += conv_len;
			if (conv_exist == 0)
			{
				i = i_before;
				if (format[i + 1] == '\0' || (format[i + 1] == ' ' &&
							      format[i + 2] == '\0'))
				{
					return (-1);
				}
				if (format[i + 1] != '\0')
				{
					_putchar(format[i]);
					len++;
				}
			}
		}
		else
		{
			_putchar(format[i]);
			len++;
		}
	}
	return (len);
}
