#include "main.h"
#include <stdarg.h>



int _printf(const char *format, ...)
{
	int i, len = 0, buf_idx;
	va_list args;
	char buf[1024];

	va_start(args, format);
	/*not used variabled*/
	(void) buf;
	(void) buf_idx;

	for (i = 0; format[i] != '\0' ; i++)
	{
			_putchar(format[i]);
			len++;
	}
	return (len);
}
