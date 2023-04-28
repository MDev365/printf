#include "main.h"
#include <stdio.h>

int handle_conversion_specification(const char *format, va_list args, int *ind, int *conv_le)
{
	int i = *ind, width = 0, precision = -1, len = 0, s_len, conv_exist = 0;
	flags_ty flags = {0, 0, 0, 0, 0, 0};
	char c_arg, *s_arg, int_buf[20], binary_buf[32], length;

	i += get_flags(&format[i + 1], &flags);
	i += get_width(&format[i + 1], &width, args);
	i += get_precision(&format[i + 1], &precision, args);
	i += get_length_modifier(&format[i + 1], &length);
	i += get_conversion_specifier(&format[i + 1], &flags);
	
	if (format[i] == 'c')
	{
		c_arg = va_arg(args, int);
		if (c_arg)
		{
			_putchar(c_arg);
			len++;
		}
		else
		{
			_putchar(0);
			len++;
		}
	}
	else if (format[i] == 's')
	{
		s_arg = va_arg(args, char *);
		s_len = print_string(s_arg, width, precision, &flags);
		len += s_len;
	}
	else if (format[i] == 'S')
	{
		s_arg = va_arg(args, char *);
		s_len = print_string_non_print(s_arg);
		len += s_len;
	}
	else if (format[i] == '%')
	{
		_putchar('%');
		len++;
	}
	else if (format[i] == 'i' || format[i] == 'd')
	{
		int_buf[0] = '\0';
		s_len = int_to_string(va_arg(args, int), int_buf, &flags, precision);
		len += print_numeric(int_buf, width, precision, &flags);
		/*len += s_len;*/
	}
	else if (format[i] == 'b')
	{
		binary_buf[0] = '\0';
		s_len = int_to_binary(va_arg(args, unsigned int), binary_buf, &flags);
		len += print_numeric(int_buf, width, precision, &flags);
		/*len += s_len;*/
	}
	else if (format[i] == 'o')
	{
		binary_buf[0] = '\0';
		s_len = int_to_octal(va_arg(args, unsigned int), binary_buf, &flags);
		len += print_numeric(int_buf, width, precision, &flags);
		/*len += s_len;*/
	}
	else if (format[i] == 'u')
	{
		binary_buf[0] = '\0';
		s_len = uint_to_string(va_arg(args, unsigned int), binary_buf, &flags);
		len += print_numeric(int_buf, width, precision, &flags);
		/*len += s_len;*/
	}
	else if (format[i] == 'x')
	{
		binary_buf[0] = '\0';
		s_len = int_to_hex(va_arg(args, unsigned int), binary_buf, 0, &flags);
		len += print_numeric(int_buf, width, precision, &flags);
		/*len += s_len;*/
	}
	else if (format[i] == 'X')
	{
		binary_buf[0] = '\0';
		s_len = int_to_hex(va_arg(args, unsigned int), binary_buf, 1, &flags);
		len += print_numeric(int_buf, width, precision, &flags);
		/*len += s_len;*/
	}
	else if (format[i] == 'p')
	{
		len += print_address(va_arg(args, void *));
		/*len += s_len;*/
	}
	else if (format[i] == 'r')
	{
		s_arg = va_arg(args, char *);
		if (s_arg)
		{
			s_len = print_reverse_string(s_arg);
			len += s_len;
		}
	}
	else if (format[i] == 'R')
	{
		s_arg = va_arg(args, char *);
		if (s_arg)
		{
			s_len = print_rot13ed_string(s_arg);
			len += s_len;
		}
	}
	else if (format[i + 1] == '\0')
		len = -1;
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
		conv_len = 0;
		conv_exist = 0;
		i_before = i;
		if (format[i] == '%')
		{
			conv_exist = handle_conversion_specification(format, args, &i, &conv_len);
			len += conv_len;
			if (conv_len == -1)
				return (-1);
			
		}
		if (conv_exist == 0)
		{
			i = i_before;
			/* (void) i_before; */
			_putchar(format[i]);
			len++;
		}
	}
	return (len);
}
