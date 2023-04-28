#include "main.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
	int i = 2;
	long int l;
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%d", 1024);
	printf("%d", 1024);
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%d", -1024);
	printf("%d", -1024);
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%d", 0);
	printf("%d", 0);
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%d", INT_MAX);
	printf("%d", INT_MAX);
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%d", INT_MIN);
	printf("%d", INT_MIN);
	
	i++;
	printf("\n============== %i ================\n", i);
	l = INT_MAX + 1024;
	_printf("%d", l);
	printf("%d", l);
	
	i++;
	printf("\n============== %i ================\n", i);
	l = INT_MIN - 1024
	_printf("%d", l);
	printf("%d", l);
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("There is %d bytes in %d KB\n", 1024, 1);
	printf("There is %d bytes in %d KB\n", 1024, 1);
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%d - %d = %d\n", 1024, 2048, -1024);
	printf("%d - %d = %d\n", 1024, 2048, -1024);
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%d + %d = %d\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));
	printf("%d + %d = %d\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%i", 1024);
	printf("%i", 1024);
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%i", -1024);
	printf("%i", -1024);
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%i", 0);
	printf("%i", 0);
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%i", INT_MAX);
	printf("%i", INT_MAX);
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%i", INT_MIN);
	printf("%i", INT_MIN);
	
	i++;
	printf("\n============== %i ================\n", i);
	l = INT_MAX + 1024;
	_printf("%i", l);
	printf("%i", l);
	
	i++;
	printf("\n============== %i ================\n", i);
	l = INT_MAX -+ 1024;
	_printf("%i", l);
	printf("%i", l);
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("There is %i bytes in %i KB\n", 1024, 1);
	printf("There is %i bytes in %i KB\n", 1024, 1);
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%i - %i = %i\n", 1024, 2048, -1024);
	printf("%i - %i = %i\n", 1024, 2048, -1024);
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%i + %i = %i\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));
	printf("%i + %i = %i\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%i + %i = %i\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));
	printf("%i + %i = %i\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("iddi%diddiiddi\n", 1024);
	printf("iddi%diddiiddi\n", 1024);
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%d", 10000);
	printf("%d", 10000);
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%i", 10000);
	printf("%i", 10000);
	
	
	
	return (1);
}

