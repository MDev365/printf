#include "main.h"
#include <stdio.h>

int main(void)
{
	int i = 3;
	
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf(NULL);
	printf(NULL);
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%c", '\0');
	printf("%c", '\0');
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("t%");
	printf("m%");
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%!\n");
	printf("%!\n");
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%K\n");
	printf("%K\n");
	
	return (1);
}
