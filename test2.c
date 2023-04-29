#include "main.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
	int i = 3;
	long int l, res;
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%u", 1024);
	printf("\n");
	printf("%u", 1024);
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%u", -1024);
	printf("\n");
	printf("%u", -1024);
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%u", 0);
	printf("\n");
	printf("%u", 0);
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%u", UINT_MAX);
	printf("\n");
	printf("%u", UINT_MAX);
	
	
	i++;
	printf("\n============== %i ================\n", i);
	l = (long int)INT_MAX + 1024;
	_printf("%u", l);
	printf("\n");
	printf("%u", l);
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("There is %u bytes in %u KB\n", 1024, 1);
	printf("There is %u bytes in %u KB\n", 1024, 1);
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%u - %u = %u\n", 2048, 1024, 1024);
	printf("%u - %u = %u\n", 2048, 1024, 1024);
	
	i++;
	printf("\n============== %i ================\n", i);
	res = (long int) INT_MAX * 2;
	_printf("%u + %u = %u\n", INT_MAX, INT_MAX, res);
	printf("%u + %u = %u\n", INT_MAX, INT_MAX, res);
	
	
	printf("\n");
	
	return (1);
}
