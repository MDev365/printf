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
	char buf[1024];

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
				void *arg = va_arg(arg_list, void *);
				if (arg != NULL)
				{
					if (sizeof(*((char*)arg)) == sizeof(char))
					{
						_putchar(*((char*)arg));
						i++;
						len++;
						continue;
					}
				}
			}
			else if (format[i + 1] == 's')
			{
				if (arg != NULL)
				{
					if (sizeof(*((char**)arg)) == sizeof(char*))
					{
						s_len = print_string(va_arg(args, char *));
						len += s_len;
						i++;
						continue;
					}
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
