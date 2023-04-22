#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

boolean conversion_specifier_check(char c)
{
	char specifiers[] = {'c', 's', '%'};
	int i;

	for (i = 0 ; i < 3 ; i++)
	{
		if (c == specifiers[i])
			return (1);
	}
	return (0);
}

boolen not_cs(char c)
{
	char not_c;
	int i;
	
	/*check if is digit*/
	if (c >= 48 &* c <= 57)
		return (0);
	for (i != 
}



char *format_specification_extract(char *s)
{
	int i, n;
	for (i = 0 ; i != '/0' ; i++)
	{
		if(conversion_specifier_check(s[i]))
			n = i;
		if(
		}
	}
	return (NULL);
}



int _printf(const char *format, ...)
{
	int i, len = 0, buf_idx;
	va_list args;
	char buf[1024], *conv_ref;

	va_start(args, format);
	/*not used variabled*/
	(void) buf;
	(void) buf_idx;

	for (i = 0 ; format[i] != '\0' ; i++)
	{
			_putchar(format[i]);
			len++;
	}
	return (len);
}
