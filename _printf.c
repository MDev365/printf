#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

/**
 * print_string_non_print - print string Non printable characters (0 < ASCII value < 32 or >= 127)
 * are printed this way: \x, followed by the ASCII code value in hexadecimal
 * (upper case - always 2 characters)
 * @s: string
 *
 * Return: lenght of the string
 */

int print_string_non_print(char *s)
{
	int i, len = 0, j, hex_c[2] = {0 , 0}, num; 

	if (s == NULL)
	{
		return (0);
	}

	for (i = 0 ; s[i] != '\0' ; i++)
	{
		/* (0 < ASCII value < 32 or >= 127) */
		if ((s[i] > 0 && s[i] < 32) || s[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');

			num = (int) s[i];
			for (j = 0 ; num > 0 ; j++)
			{	
				hex_c[j] = num % 16;
				num = num / 16;
			}

			for (j = j - 1; j >= 0 ; j--)
			{
				if (hex_c[j] < 10)
				{
					_putchar(hex_c[j] + '0');
				}
				else if (hex_c[j] >= 10)
				{
					_putchar((hex_c[j] - 10) + 'A');
				}
			}
			len += 4;
		}
		else
		{
			_putchar(s[i]);
			len++;
		}
	}
	return (len);
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
	char buf[1024], c_arg, *s_arg, int_buf[11], binary_buf[32];

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
			else if (format[i + 1] == 'S')
			{
				s_arg = va_arg(args, char *);
				if (s_arg)
				{
					s_len = print_string_non_print(s_arg);
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
		}
			_putchar(format[i]);
			len++;
	}
	return (len);
}
