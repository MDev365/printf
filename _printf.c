#include "main.h"
int _printf(const char *format, ...)
{
	int i, len = 0;

	for (i = 0; format[i] != '\0' ; i++)
	{
		while (format[i] != '%')
		{
			_putchar(format[i]);
			i++;
			len++;
		}
		if (format[i] == '%')
		{
			_putchar(format[i]);
			i++;
		}
	}
	return (len);
}
