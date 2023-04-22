#include "main.h"
int _printf(const char *format, ...)
{
	int i, cs = 0, buf_i = 0;
	char *buf;

	/*not used yet variables*/
	(void)buf;
	(void)buf_i;
	
	for (i = 0; format[i] != '\0' ; i++)
	{
		while (format[i] != '%')
		{
			_putchar(format[i]);
			i++;
		}
		if (format[i] == '%')
		{
			_putchar(format[i]);
			i++;
		}
	}
	return (i);
}
