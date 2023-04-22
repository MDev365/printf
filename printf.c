#include "main.h"
int _printf(const char *format, ...)
{
	int i, cs = 0, buf_i = 0;
	char *buf;

	/*not used yet variables*/
	(void)buf;
	(void)buf_int;
	
	for (i = 0; format[i] != '\0' ; i++)
	{
		while (format[i] != '%')
		{
			_putchar(format[i]);
			i++;
		}
		if (format[i] == '%')
		{
			i++;
			while (cs == 0)
			{
			}
		}
	}
	return (i);
}
