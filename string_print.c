#include "main.h"


/**
 * print_address - print address
 * @p: pointer
 *
 * Return: lenght of the string
 */

int print_address(void *p)
{
	int i, len = 0, non_zero_digit_found = 0;
	unsigned long addr = (unsigned long) p;
	char hex[16] = "0123456789abcdef";
	unsigned char digit;

	if (p == NULL || (sizeof(p) != sizeof(void *)))
		return (print_string("(nil)"));

	_putchar('0');
	_putchar('x');
	len += 2;
	for (i = sizeof(addr) * 2 - 1; i >= 0; i--)
	{
		digit = (addr >> (i * 4)) & 0xF;
		if (digit != 0 || non_zero_digit_found)
		{
			non_zero_digit_found = 1;
			_putchar(hex[digit]);
			len++;
		}
	}

	return (len);
}



/**
 * print_string_non_print - print string Non printable characters
 * are printed this way: \x, followed by the ASCII code value in hexadecimal
 * (upper case - always 2 characters)
 * @s: string
 *
 * Return: lenght of the string
 */

int print_string_non_print(char *s)
{
	int i, len = 0, j, hex_c[2] = {0, 0}, num;

	if (s == NULL)
	{
		s = "(null)";
	}

	for (i = 0 ; s[i] != '\0' ; i++)
	{
		/* (0 < ASCII value < 32 or >= 127) */
		if ((s[i] > 0 && s[i] < 32) || s[i] >= 127)
		{
			_putchar(92);
			_putchar('x');

			hex_c[0] = 0;
			hex_c[1] = 0;
			num = (int) s[i];
			for (j = 0 ; num > 0 ; j++)
			{
				hex_c[j] = num % 16;
				num = num / 16;
			}

			for (j = 1 ; j >= 0 ; j--)
			{
				if (hex_c[j] < 10)
					_putchar(hex_c[j] + '0');
				else if (hex_c[j] >= 10)
					_putchar((hex_c[j] - 10) + 'A');
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
 * print_reverse_string - print string
 * @s: string
 *
 * Return: lenght of the string
 */
int print_reverse_string(char *s)
{
	int i, len;

	if (s == NULL)
	{
		s = "(null)";
	}

	for (i = 0 ; s[i] != '\0' ; i++)
	{
	}
	len = i;

	for (i = i - 1 ; i >= 0 ; i--)
	{
		_putchar(s[i]);
	}

	return (len);
}

/**
 * print_rot13ed_string - print string
 * @s: string
 *
 * Return: lenght of the string
 */
int print_rot13ed_string(char *s)
{
	int i;

	if (s == NULL)
	{
		s = "(null)";
	}

	for (i = 0 ; s[i] != '\0' ; i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			if (s[i] + 13 > 'Z')
				_putchar(s[i] - 13);
			else
				_putchar(s[i] + 13);
		}
		else if (s[i] >= 'a' && s[i] <= 'z')
		{
			if (s[i] + 13 > 'z')
				_putchar(s[i] - 13);
			else
				_putchar(s[i] + 13);
		}
		else
		{
			_putchar(s[i]);
		}
	}
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
		if (null == 1)
			len = 0;
		else
			len = precision;
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
		for (i = 0 ; i < len ; i++)
			_putchar(s[i]);
		return (i);
	}
}
