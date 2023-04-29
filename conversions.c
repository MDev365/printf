#include "main.h"
#include <stdio.h>


/**
 * handle_zero - convert int to string
 * @buf: number buffer
 * @flags: flags
 * @precision: precision
 *
 * Return: length of the string
 */
int handle_zero(char *buf, flags_ty *flags, int precision)
{
	int j = 0;

	if (precision == 0)
	{
		if (flags->plus > 0)
		{
			buf[j] = '+';
			j++;
		}
		else if (flags->space > 0)
		{
			buf[j] = ' ';
			j++;
		}
	}
	else
	{
		if (flags->plus > 0)
		{
			buf[j] = '+';
			j++;
		}
		else if (flags->space > 0)
		{
			buf[j] = ' ';
			j++;
		}
		buf[j] = '0';
		j++;
	}
	buf[j] = '\0';
	return (1);
}

/**
 * int_to_string - convert int to string
 * @num: the integer number
 * @buf: number buffer
 * @flags: flags
 * @precision: precision
 *
 * Return: length of the string
 */
int int_to_string(va_list args, char *buf, flags_ty *flags, int precision)
{
	int neg = 0, i, j = 0;
	int digits_array[40];
	unsigned int local_num;
	unsigned long ul;
	unsigned short uh;

	if (flags->length == 'l')
	{
		ul = va_arg(args, unsigned long);
		if (ul == 0)
			return (handle_zero(buf, flags, precision));
		for (i = 0 ; ul > 0 ; i++)
		{
			digits_array[i] = ul % 10;
			ul = ul / 10;
		}
	}
	else if (flags->length == 'h')
	{
		uh = va_arg(args, unsigned short);
		if (uh == 0)
			return (handle_zero(buf, flags, precision));
		for (i = 0 ; uh > 0 ; i++)
		{
			digits_array[i] = uh % 10;
			uh = uh / 10;
		}
	}
	else
	{
		num = va_arg(args, int);
		if (num == 0)
			return (handle_zero(buf, flags, precision));
		else if (num < 0)
		{
			neg = 1;
			local_num = (unsigned int)(num * -1);
		}
		else
		{
			local_num = (unsigned int)num;
		}

		for (i = 0 ; local_num > 0 ; i++)
		{
			digits_array[i] = local_num % 10;
			local_num = local_num / 10;
		}
	}
	
	if (neg == 1 && flags->length != 'l' && flags->length != 'l')
	{
		buf[j] = '-';
		j++;
	}
	else if (flags->plus > 0)
	{
		buf[j] = '+';
		j++;
	}
	else if (flags->space > 0)
	{
		buf[j] = ' ';
		j++;
	}
	for (i = i - 1; i >= 0 ; i--)
	{
		buf[j] = digits_array[i] + '0';
		j++;
	}
	buf[j] = '\0';
	return (j);
}
