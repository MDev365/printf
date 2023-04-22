#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

/**
 * print_string - print string
 * @s: string
 *
 * Return: lenght of the string
 */

int print_string(char *s)
{
	int i;

	if (s == NULL)
	{
		return (0);
	}

	for (i = 0 ; s[i] != '\0' ; i++)
	{
		_putchar(s[i]);
	}
	return (i);
}

/**
 * _printf - printf replica
 * @format: format
 *
 * Return: lenght of the string printed
 */
int _printf(const char *format, ...)
{
	int i, len = 0, buf_idx, s_len;
	va_list args;
	char buf[1024], c_arg, *s_arg;

	va_start(args, format);
	/*not used variabled*/
	(void) buf;
	(void) buf_idx;

	for (i = 0 ; format[i] != '\0' ; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
			{
				c_arg = va_arg(args, int);
				if (c_arg != NULL)
				{
					_putchar(c_arg));
					i++;
					len++;
					continue;
				}
			}
			else if (format[i + 1] == 's')
			{
				s_arg = va_arg(args, char *);
				if (s_arg != NULL)
				{
					s_len = print_string(s_arg);
					len += s_len;
					i++;
					continue;
				}
			}
			else if (format[i + 1] == '%')
			{
				_putchar('%');
				len++;
				i++;
				continue;
			}
		}
			_putchar(format[i]);
			len++;
	}
	return (len);
}
