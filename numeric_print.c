#include "main.h"

/**
 * print_pre_diff - print pre_diff
 * @pre_diff: int
 *
 * Return: void
 */
void  print_pre_diff(int pre_diff)
{
	for (; pre_diff > 0 ; pre_diff--)
	{
		_putchar('0');
	}
}


/**
 * print_width_diff - print width_diff
 * @width_diff: int
 * @c: width diff char
 *
 * Return: void
 */
void  print_width_diff(int width_diff, char c)
{
	for (; width_diff > 0 ; width_diff--)
	{
		_putchar(c);
	}
}


/**
 * print_number - print number
 * @s: char *
 *
 * Return: void
 */
void  print_number(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		_putchar(s[i]);
		i++;
	}
}

/**
 * print_prefix - print prefix
 * @s: char *
 * @prefix_len: prefix len
 *
 * Return: prefix len
 */
int  print_prefix(char *s, int prefix_len)
{
	int i = 0;

	for (i = 0; i < prefix_len ; i++)
	{
		_putchar(s[i]);
	}
	return (prefix_len);
}

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
	int j = 0, len, pre_diff = 0, width_diff = 0, prefix = 0;

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
			j += print_prefix(&s[j], prefix);
			print_pre_diff(pre_diff);
			print_number(&s[j]);
			print_width_diff(width_diff, ' ');
			return (prefix + pre_diff + len + width_diff);
		}
		else
		{
			if (flags->zero == 0 || precision >= 0)
				print_width_diff(width_diff, ' ');
			j += print_prefix(&s[j], prefix);
			if (flags->zero > 0 || precision < 0)
				print_width_diff(width_diff, '0');
			print_pre_diff(pre_diff);
			print_number(&s[j]);
			return (prefix + pre_diff + len + width_diff);
		}
	}
	else
	{
		j += print_prefix(&s[j], prefix);
		print_pre_diff(pre_diff);
		print_number(&s[j]);
		return (prefix + pre_diff + len + width_diff);
	}
}
