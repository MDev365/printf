#include "main.h"

/**
 * print_numeric - print string
 * @s: string
 * @width: width
 * @precision: precision
 * @flags: flags
 *
 * Return: lenght of the string
 */
int print_numeric(char *s, int width, int precision, flags_ty *flags)
{
	int i, j = 0, k, len, pre_diff = 0, width_diff = 0, null = 0, prefix = 0;

	len = _strlen(s);
	if ((s[0] == '0' && len == 1 && precision == 0) || s[0] == '\0')
	{
		return (0);
	}

	/* check if there is sign or prefixes */
	if (s[0] == '+' || s[0] == '-' || s[0] == ' ' || s[0] == '0')
		prefix = 1;
	else if (s[1] == 'x' || s[1] == 'X')
		prefix = 2;

	/* ----- */
	len -= prefix;
	if (precision > len)
	{
		pre_diff = precision - len;
	}
	if (width > (len + pre_diff + prefix))
	{
		width_diff = width - (len + pre_diff + prefix);
		if (flags->minus > 0)
		{
			/* 1 print prefix */
			for (i = 0; i < prefix ; i++)
			{
				_putchar(s[j]);
				j++;
			}

			/* 2 print precision diff */
			for (i = 0; i < pre_diff ; i++)
			{
				_putchar('0');
			}
			/* 3 print the number */
			while (s[j] != '\0')
			{
				_putchar(s[j]);
				j++;
			}
			/* 4 print width diff as ' ' */
			for (k = 0 ; k < width_diff ; k++)
			{
				_putchar(' ');
			}
			return (prefix + pre_diff + len + width_diff);
		}
		else
		{
			for (k = 0 ; k < width_diff ; k++)
			{
				if (flags->zero > 0)
					_putchar('0');
				else
					_putchar(' ');
			}
			/* print prefix */
			for (i = 0; i < prefix ; i++)
			{
				_putchar(s[j]);
				j++;
			}
			/* print precision diff */
			for (i = 0; i < pre_diff ; i++)
			{
				_putchar('0');
			}
			/* ----- */
			while (s[j] != '\0')
			{
				_putchar(s[j]);
				j++;
			}
			return (prefix + pre_diff + len + width_diff);
		}
	}
}
