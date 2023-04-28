#include "main.h"
#include <stdio.h>

int main(void)
{
	int i = 3;
	
	
	i++;
	_printf("\n============== %i ================\n", i);
	_printf(NULL);
	printf(NULL);
	
	i++;
	_printf("\n============== %i ================\n", i);
	_printf("%c", '\0');
	printf("%c", '\0');
	
	i++;
	_printf("\n============== %i ================\n", i);
	_printf("%");
	printf("%");
	
	i++;
	_printf("\n============== %i ================\n", i);
	_printf("%!\n");
	printf("%!\n");
	
	i++;
	_printf("\n============== %i ================\n", i);
	_printf("%K\n");
	printf("%K\n");
	
	return (1);
}
