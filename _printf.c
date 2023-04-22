#include "main.h"
int _printf(const char *format, ...)
{
	int i, len = 0;
	char buf[1024];

	/*not used variabled*/
	(void) buf;

	for (i = 0; format[i] != '\0' ; i++)
	{
			_putchar(format[i]);
			len++;
	}
	return (len);
}
