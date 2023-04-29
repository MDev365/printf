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
int int_to_string(int num, char *buf, flags_ty *flags, int precision)
{
	int neg = 0, i, j = 0;
	int digits_array[20];
	unsigned int local_num;

	if (num == 0)
		return (handle_zero(buf, &flags, precision));
	else if (num < 0)
	{
		neg = 1;
		local_num = (unsigned int)(num * -1);
	}
	else
	{
		local_num = (unsigned int)num;
	}

	/* convert number into array of digits */
	for (i = 0 ; local_num > 0 ; i++)
	{
		digits_array[i] = local_num % 10;
		local_num = local_num / 10;
	}

	/*check for negative and flags */
	if (neg == 1)
	{
		buf[j] = '-';
		j++;
	}
	else if (flags->plus > 1)
	{
		buf[j] = '+';
		j++;
	}
	else if (flags->space > 1)
	{
		buf[j] = ' ';
		j++;
	}

	/* convert digits into string */
	for (i = i - 1; i >= 0 ; i--)
	{
		buf[j] = digits_array[i] + '0';
		j++;
	}

	buf[j] = '\0';

	return (j);
}
