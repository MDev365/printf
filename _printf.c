#include "main.h"
#include <stdarg.h>
#include <stdlib.h>


char *check_flag(char *s)
{
	char flags[] = {'-', '+', ' ', '\'', 'I'};
	int i;
	char *number;

	if (s[0] >= 48 && s[0] <= 57)
		
	while (s[i] >= 48 && s[i] <= 57)
	{
		
	}
}

boolean conversion_specifier_check(char c)
{
	char specifiers[] = {'c', 's', '%'};
	int i;

	for (i = 0 ; i < 3 ; i++)
	{
		if (c == specifiers[i])
			return (1);
	}
	return (0);
}



boolen not_cs(char c)
{
	char not_c;
	int i;
	
	/*check if is digit*/
	if (c >= 48 &* c <= 57)
		return (0);
}


char *format_specification_extract(char *s)
{
	int i, n;
	for (i = 0 ; i != '/0' ; i++)
	{
		if(conversion_specifier_check(s[i]))
			n = i;
		}
	}
	return (NULL);
}


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
		i++;
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
	char buf[1024], *conv_ref;

	va_start(args, format);
	/*not used variabled*/
	(void) buf;
	(void) buf_idx;

	for (i = 0 ; format[i] != '\0' ; i++)
	{
		if (format[i] == '%')
		{
			if (format [i + 1] == 'c')
			{
				_putchar(va_arg(args, char));
				i += 2;
				len++;
				continue;
			}
			else if (format[i + 1] == 's')
			{
				s_len = print_string(va_arg(args, char *));
				len += s_len;
				i += 2;
				continue;
			}
		}
			_putchar(format[i]);
			len++;
	}
	return (len);
}
