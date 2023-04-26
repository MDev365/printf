#include "main.h"

/* get_conv_spec - get conversion specefication
 * @format: format string
 * @args; va_list
 *
 * Return: length
 */
int get_conv_spec(const char *format, va_list args)
{
	int i = 0, len = 0, s_len;
	char c_arg, *s_arg, int_buf[11], binary_buf[32];

	if (format[i + 1] == 'c')
	{
		c_arg = va_arg(args, int);
		if (c_arg)
		{
			_putchar(c_arg);
			len++;
		}
	}
	else if (format[i + 1] == 's')
	{
		s_arg = va_arg(args, char *);
		if (s_arg)
		{
			s_len = print_string(s_arg);
			len += s_len;
		}
	}
	else if (format[i + 1] == 'S')
	{
		s_arg = va_arg(args, char *);
		if (s_arg)
		{
			s_len = print_string_non_print(s_arg);
			len += s_len;
		}
	}
	else if (format[i + 1] == '%')
	{
		_putchar('%');
		len++;
	}
	else if (format[i + 1] == 'i' || format[i + 1] == 'd')
	{
		int_buf[0] = '\0';
		len += int_to_string(va_arg(args, int), int_buf);
		s_len = print_string(int_buf);

	}
	else if (format[i + 1] == 'b')
	{
		binary_buf[0] = '\0';
		len += int_to_binary(va_arg(args, unsigned int), binary_buf);
		s_len = print_string(binary_buf);
	}
	else if (format[i + 1] == 'o')
	{
		binary_buf[0] = '\0';
		len += int_to_octal(va_arg(args, unsigned int), binary_buf);
		s_len = print_string(binary_buf);
	}
	else if (format[i + 1] == 'u')
	{
		binary_buf[0] = '\0';
		len += uint_to_string(va_arg(args, unsigned int), binary_buf);
		s_len = print_string(binary_buf);
	}
	else if (format[i + 1] == 'x')
	{
		binary_buf[0] = '\0';
		len += int_to_hex(va_arg(args, unsigned int), binary_buf, 0);
		s_len = print_string(binary_buf);
	}
	else if (format[i + 1] == 'X')
	{
		binary_buf[0] = '\0';
		len += int_to_hex(va_arg(args, unsigned int), binary_buf, 1);
		s_len = print_string(binary_buf);
	}
	else if (format[i + 1] == 'p')
	{
		len += print_address(va_arg(args, void *));
	}
	else if (format[i + 1] == 'r')
	{
		s_arg = va_arg(args, char *);
		if (s_arg)
		{
			s_len = print_reverse_string(s_arg);
			len += s_len;
		}
	}
	else if (format[i + 1] == 'R')
	{
		s_arg = va_arg(args, char *);
		if (s_arg)
		{
			s_len = print_rot13ed_string(s_arg);
			len += s_len;
		}
	}
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
	int i, len = 0, buf_idx, conve_spec_len;
	char buf[1024];
	va_list args;

	va_start(args, format);
	/*not used variabled*/
	(void) buf;
	(void) buf_idx;

	for (i = 0 ; format[i] != '\0' ; i++)
	{
		if (format[i] == '%')
		{
			conve_spec_len = get_conv_spec(&format[i], args);
			if (conve_spec_len > 0)
			{
				len += conve_spec_len;
				i++;
				continue;
			}
		}
			_putchar(format[i]);
			len++;
	}
	return (len);
}
