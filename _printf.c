#include "main.h"

/**
 * get_flags - get format flag
 * @s: format string
 * @flags: flags struct
 *
 * Return: int
 */
int get_flags(const char *s, flags_ty *flags)
{
	int i = 0;

	while (s[i] == '+' || s[i] == ' ' || s[i] == '#')
	{
		if (s[i] == '+')
			flags->plus += 1;
		else if (s[i] == ' ')
			flags->space += 1;
		else if (s[i] == '#')
			flags->hash += 1;
		i++;
	}
	return (i);
}

/**
 * get_width - get format flag
 * @s: format string
 * @width: flags struct
 * @args: va_list args
 *
 * Return: int
 */
int get_width(const char *s, int *width, va_list args)
{
	int i = 0;

	if (s[i] == '*')
	{
		*width = va_arg(args, int);
		return (1);
	}
	*width = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		*width = (*width * 10) + ((s[i]) - '0');
		i++;
	}

	return (i);
}


/**
 * get_precision - get format flag
 * @s: format string
 * @precision: flags struct
 * @args: va_list args
 *
 * Return: int
 */
int get_precision(const char *s, int *precision, va_list args)
{
	int i = 0;

	if (s[i] == '.')
	{
		i++;
		if (s[i] == '*')
		{
			*precision = va_arg(args, int);
			return (1);
		}
		*precision = 0;
		while (s[i] >= '0' && s[i] <= '9')
		{
			*precision = (*precision * 10) + ((s[i]) - '0');
			i++;
		}
		return (i);
	}
	else
	{
		return (0);
	}
}

/**
 * get_length_modifier - get format flag
 * @s: format string
 * @length: flags struct
 *
 * Return: int
 */
int get_length_modifier(const char *s, char *length)
{
	int i = 0;

	if (s[i] == 'l')
	{
		*length = 'l';
		return (1);
	}
	else if (s[i] == 'h')
	{
		*length = 'h';
		return (1);
	}
	return (0);
}


/**
 * _printf - printf replica
 * @format: format
 *
 * Return: lenght of the string printed
 */
int _printf(const char *format, ...)
{
	int i, i_before, len = 0, buf_idx, s_len, width, precision;
	char length;
	va_list args;
	char buf[1024], c_arg, *s_arg, int_buf[12], binary_buf[32];
	flags_ty flags = {0, 0, 0};

	va_start(args, format);
	/*not used variabled*/
	(void) buf;
	(void) buf_idx;

	if (format == NULL)
		return (0);

	for (i = 0 ; format[i] != '\0' ; i++)
	{
		i_before = i;
		if (format[i] == '%')
		{
			width = 0;
			precision = 0;
			length = 0;
			i += get_flags(&format[i + 1], &flags);
			i += get_width(&format[i + 1], &width, args);
			i += get_precision(&format[i + 1], &precision, args);
			i += get_length_modifier(&format[i + 1], &length);
			if (format[i + 1] == 'c')
			{
				c_arg = va_arg(args, int);
				if (c_arg)
				{
					_putchar(c_arg);
					i++;
					len++;
				}
				continue;
			}
			else if (format[i + 1] == 's')
			{
				s_arg = va_arg(args, char *);
				if (s_arg)
				{
					s_len = print_string(s_arg);
					len += s_len;
					i++;
				}
				continue;
			}
			else if (format[i + 1] == 'S')
			{
				s_arg = va_arg(args, char *);
				if (s_arg)
				{
					s_len = print_string_non_print(s_arg);
					len += s_len;
					i++;
				}
				continue;
			}
			else if (format[i + 1] == '%')
			{
				_putchar('%');
				len++;
				i++;
				continue;
			}
			else if (format[i + 1] == 'i' || format[i + 1] == 'd')
			{
				int_buf[0] = '\0';
				len += int_to_string(va_arg(args, int), int_buf);
				s_len = print_string(int_buf);
				/*len += s_len;*/
				i++;
				continue;
			}
			else if (format[i + 1] == 'b')
			{
				binary_buf[0] = '\0';
				len += int_to_binary(va_arg(args, unsigned int), binary_buf);
				s_len = print_string(binary_buf);
				/*len += s_len;*/
				i++;
				continue;
			}
			else if (format[i + 1] == 'o')
			{
				binary_buf[0] = '\0';
				len += int_to_octal(va_arg(args, unsigned int), binary_buf);
				s_len = print_string(binary_buf);
				/*len += s_len;*/
				i++;
				continue;
			}
			else if (format[i + 1] == 'u')
			{
				binary_buf[0] = '\0';
				len += uint_to_string(va_arg(args, unsigned int), binary_buf);
				s_len = print_string(binary_buf);
				/*len += s_len;*/
				i++;
				continue;
			}
			else if (format[i + 1] == 'x')
			{
				binary_buf[0] = '\0';
				len += int_to_hex(va_arg(args, unsigned int), binary_buf, 0);
				s_len = print_string(binary_buf);
				/*len += s_len;*/
				i++;
				continue;
			}
			else if (format[i + 1] == 'X')
			{
				binary_buf[0] = '\0';
				len += int_to_hex(va_arg(args, unsigned int), binary_buf, 1);
				s_len = print_string(binary_buf);
				/*len += s_len;*/
				i++;
				continue;
			}
			else if (format[i + 1] == 'p')
			{
				len += print_address(va_arg(args, void *));
				/*len += s_len;*/
				i++;
				continue;
			}
			else if (format[i + 1] == 'r')
			{
				s_arg = va_arg(args, char *);
				if (s_arg)
				{
					s_len = print_reverse_string(s_arg);
					len += s_len;
					i++;
					continue;
				}
			}
			else if (format[i + 1] == 'R')
			{
				s_arg = va_arg(args, char *);
				if (s_arg)
				{
					s_len = print_rot13ed_string(s_arg);
					len += s_len;
					i++;
					continue;
				}
			}
		}
		i = i_before;
		_putchar(format[i]);
		len++;
	}
	return (len);
}
