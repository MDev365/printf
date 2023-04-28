/**
 * get_flags - get format flag
 * @s: format string
 * @flags: flags struct
 *
 * Return: int
 */
int get_flags(const char *s, flags_ty *flags)
{
	int i = 0;

	while (s[i] == '+' || s[i] == ' ' || s[i] == '#')
	{
		if (s[i] == '+')
			flags->plus += 1;
		else if (s[i] == ' ')
			flags->space += 1;
		else if (s[i] == '#')
			flags->hash += 1;
		else if (s[i] == '0')
			flags->zero += 1;
		else if (s[i] == '-')
			flags->minus += 1;
		i++;
	}
	return (i);
}

/**
 * get_width - get format flag
 * @s: format string
 * @width: flags struct
 * @args: va_list args
 *
 * Return: int
 */
int get_width(const char *s, int *width, va_list args)
{
	int i = 0;

	if (s[i] == '*')
	{
		*width = va_arg(args, int);
		return (1);
	}
	*width = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		*width = (*width * 10) + ((s[i]) - '0');
		i++;
	}

	return (i);
}


/**
 * get_precision - get format flag
 * @s: format string
 * @precision: flags struct
 * @args: va_list args
 *
 * Return: int
 */
int get_precision(const char *s, int *precision, va_list args)
{
	int i = 0;

	if (s[i] == '.')
	{
		i++;
		if (s[i] == '*')
		{
			*precision = va_arg(args, int);
			return (1);
		}
		*precision = 0;
		while (s[i] >= '0' && s[i] <= '9')
		{
			*precision = (*precision * 10) + ((s[i]) - '0');
			i++;
		}
		return (i);
	}
	else
	{
		return (0);
	}
}

/**
 * get_length_modifier - get format flag
 * @s: format string
 * @length: flags struct
 *
 * Return: int
 */
int get_length_modifier(const char *s, char *length)
{
	int i = 0;

	if (s[i] == 'l')
	{
		*length = 'l';
		return (1);
	}
	else if (s[i] == 'h')
	{
		*length = 'h';
		return (1);
	}
	return (0);
}
