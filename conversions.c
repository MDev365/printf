#include "main.h"

/**
 * uint_to_string - convert int to string
 * @num: the integer number
 * @buf: number buffer
 *
 * Return: length of the string
 */
int uint_to_string(unsigned int num, char *buf)
{
	int i, j = 0;
	int digits_array[32];

	if (num == 0)
	{
		buf[0] = '0';
		buf[1] = '\0';
		return (1);
	}

	for (i = 0 ; num > 0 ; i++)
	{
		digits_array[i] = num % 10;
		num = num / 10;
	}

	for (i = i - 1; i >= 0 ; i--)
	{
		buf[j] = digits_array[i] + '0';
		j++;
	}

	buf[j] = '\0';

	return (j);
}

/**
 * int_to_octal - convert int to string
 * @num: the integer number
 * @buf: number buffer
 *
 * Return: length of the string
 */
int int_to_octal(unsigned int num, char *buf)
{
	int i, j = 0;
	int digits_array[32];

	if (num == 0)
	{
		buf[0] = '0';
		buf[1] = '\0';
		return (1);
	}

	for (i = 0 ; num > 0 ; i++)
	{
		digits_array[i] = num % 8;
		num = num / 8;
	}

	for (i = i - 1; i >= 0 ; i--)
	{
		buf[j] = digits_array[i] + '0';
		j++;
	}

	buf[j] = '\0';

	return (j);
}

/**
 * int_to_binary - convert int to string
 * @num: the integer number
 * @buf: number buffer
 *
 * Return: length of the string
 */
int int_to_binary(unsigned int num, char *buf)
{
	int i, j = 0;
	int digits_array[32];

	if (num == 0)
	{
		buf[0] = '0';
		buf[1] = '\0';
		return (1);
	}

	for (i = 0 ; num > 0 ; i++)
	{
		digits_array[i] = num % 2;
		num = num / 2;
	}

	for (i = i - 1; i >= 0 ; i--)
	{
		buf[j] = digits_array[i] + '0';
		j++;
	}

	buf[j] = '\0';

	return (j);
}

/**
 * int_to_string - convert int to string
 * @num: the integer number
 * @buf: number buffer
 *
 * Return: length of the string
 */
int int_to_string(int num, char *buf)
{
	int neg = 0, i, j = 0;
	int digits_array[11];

	if (num == 0)
	{
		buf[0] = '0';
		buf[1] = '\0';
		return (1);
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
	}

	if (neg == 1)
	{
		buf[j] = '-';
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
