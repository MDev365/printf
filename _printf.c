#include "main.h"

int handle_conversion_specification(const char *format, va_list args, int *ind)
{
	int i = *ind, width = 0, precision = -1, length = 0, len = 0, s_len;
	flags_ty flags = {0, 0, 0, 0, 0, 0};
	char buf[1024], c_arg, *s_arg, int_buf[20], binary_buf[32];

	i += get_flags(&format[i + 1], &flags);
	i += get_width(&format[i + 1], &width, args);
	i += get_precision(&format[i + 1], &precision, args);
	i += get_length_modifier(&format[i + 1], &length);
	i += get_conversion_specifier(&format[i + 1], &flags);
	if (format[i + 1] == 'c')
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
		i++;
	}
	else if (format[i + 1] == 's')
	{
		s_arg = va_arg(args, char *);
		s_len = print_string(s_arg, width, precision, &flags);
		len += s_len;
		i++;
	}
	else if (format[i + 1] == 'S')
	{
		s_arg = va_arg(args, char *);
		s_len = print_string_non_print(s_arg);
		len += s_len;
		i++;
	}
	else if (format[i + 1] == '%')
	{
		_putchar('%');
		len++;
		i++;
	}
	else if (format[i + 1] == 'i' || format[i + 1] == 'd')
	{
		int_buf[0] = '\0';
		len += int_to_string(va_arg(args, int), int_buf);
		s_len = print_numeric(int_buf, width, precision, &flags);
		/*len += s_len;*/
		i++;
	}
	else if (format[i + 1] == 'b')
	{
		binary_buf[0] = '\0';
		len += int_to_binary(va_arg(args, unsigned int), binary_buf);
		s_len = print_numeric(int_buf, width, precision, &flags);
		/*len += s_len;*/
		i++;
	}
	else if (format[i + 1] == 'o')
	{
		binary_buf[0] = '\0';
		len += int_to_octal(va_arg(args, unsigned int), binary_buf);
		s_len = print_numeric(int_buf, width, precision, &flags);
		/*len += s_len;*/
		i++;
	}
	else if (format[i + 1] == 'u')
	{
		binary_buf[0] = '\0';
		len += uint_to_string(va_arg(args, unsigned int), binary_buf);
		s_len = print_numeric(int_buf, width, precision, &flags);
		/*len += s_len;*/
		i++;
	}
	else if (format[i + 1] == 'x')
	{
		binary_buf[0] = '\0';
		len += int_to_hex(va_arg(args, unsigned int), binary_buf, 0);
		s_len = print_numeric(int_buf, width, precision, &flags);
		/*len += s_len;*/
		i++;
	}
	else if (format[i + 1] == 'X')
	{
		binary_buf[0] = '\0';
		len += int_to_hex(va_arg(args, unsigned int), binary_buf, 1);
		s_len = print_numeric(int_buf, width, precision, &flags);
		/*len += s_len;*/
		i++;
	}
	else if (format[i + 1] == 'p')
	{
		len += print_address(va_arg(args, void *));
		/*len += s_len;*/
		i++;
	}
	else if (format[i + 1] == 'r')
	{
		s_arg = va_arg(args, char *);
		if (s_arg)
		{
			s_len = print_reverse_string(s_arg);
			len += s_len;
		}
		i++;
	}
	else if (format[i + 1] == 'R')
	{
		s_arg = va_arg(args, char *);
		if (s_arg)
		{
			s_len = print_rot13ed_string(s_arg);
			len += s_len;
		}
		i++;
	}
	*ind = i;
	return (len);
}

/**
 * _printf - printf replica
 * @format: format
 *
 * Return: lenght of the string printed
 */
int _printf(const char *format, ...)
{
	int i, i_before, len = 0, buf_idx, conv_len == 0;
	char length;
	va_list args;
	char buf[1024], c_arg, *s_arg, int_buf[20], binary_buf[32];

	va_start(args, format);
	/*not used variabled*/
	(void) buf;
	(void) buf_idx;

	if (format == NULL)
		return (-1);

	for (i = 0 ; format[i] != '\0' ; i++)
	{
		i_before = i;
		if (format[i] == '%')
		{
			conv_len = handle_conversion_specification(format, args, &i);
			len += conv_len;
			if (conv_len == 0 && format[i + 1] == '\0')
				return (-1);
		}
		if (conv_len == 0)
		{
			i = i_before;
			/* (void) i_before; */
			_putchar(format[i]);
			len++;
		}
	}
	return (len);
}
