#include "main.h"



/**
 * putstr - putstr
 * @s: string
 * @len: length
 *
 * Return: len
 */
int putstr(char *s, int len)
{
	int i;

	for (i = 0 ; i < len || s[i] !='\0' ; i++)
			_putchar(s[i]);
	return (i);
}


/**
 * print_string - print string
 * @s: string
 * @width: width
 * @precision: precision
 * @flags: flags
 *
 * Return: lenght of the string
 */
int print_string(char *s, int width, int precision, flags_ty *flags)
{
	int i, j, len, width_diff, null = 0;

	if (s == NULL)
	{
		s = "(null)";
		null = 1;
	}
	len = _strlen(s);
	if ((precision < len) && (precision >= 0))
	{
		if (null == 1)
			len = 0;
		else
			len = precision;
	}
	if (width > len)
	{
		width_diff = width - len;
		if (flags->minus > 0)
		{
			for (i = 0 ; i < len ; i++)
				_putchar(s[i]);
			for (j = 0 ; j < width_diff ; j++)
				_putchar(' ');
			return (i + j);
		}
		else
		{
			for (j = 0 ; j < width_diff ; j++)
				_putchar(' ');
			for (i = 0 ; i < len ; i++)
				_putchar(s[i]);
			return (i + j);
		}
	}
	else
	{
		return (putstr(s, len));
	}
}
