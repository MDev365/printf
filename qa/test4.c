#include "main.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
	int i = 3;
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%6d", 102498402);
	printf("\n");
	_printf("%6d", 102498402);
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%6d", -102498402);
	printf("\n");
	printf("%6d", -102498402);
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%6d", 0);
	printf("\n");
	printf("%6d", 0);
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%6d", 1024);
	printf("\n");
	printf("%6d", 1024);
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%6d", -1024);
	printf("\n");
	printf("%6d", -1024);
  
	i++;
	printf("\n============== %i ================\n", i);
	_printf("In the middle %6d of a sentence.\n", 1024);
	printf("\n");
	printf("In the middle %6d of a sentence.\n", 1024);
	
	printf("\n");
	
	return (1);
}
