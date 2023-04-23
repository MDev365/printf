#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

/**
 * int_to_string - convert int to string
 * @num; the integer number
 * @buf; number buffer
 *
 * Return: length of the string
 */
int int_to_string(int num, char *buf)
{
    int c, len = 0, neg = 0, i, j = 0;
    int digits_array[11];
    
    if (num == 0)
    {
        buf[0] = '0';
        buf[1] = '\0';
        return(1);
    }
    if (num < 0)
    {
        neg = 1;
        num *= -1;
    }
    for (i = 0 ; num > 0 ; i++)
    {
        digits_array[i] = num % 10;
        num = num / 10;
        len++;
    }

    if (neg == 1)
    {
        buf[j] = '-';
        j++;
    }

    for (i = len - 1 ; i >= 0 ; i--)
    {
        buf[j] = digits_array[i] + '0';
        j++;
    }

    buf[j] = '\0';

    return (j);
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
				if (c_arg)
				{
					_putchar(c_arg);
					i++;
					len++;
					continue;
				}
			}
			else if (format[i + 1] == 's')
			{
				s_arg = va_arg(args, char *);
				if (s_arg)
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
