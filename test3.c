#include "main.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
	int i = 3;
	long int l;
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%+d", 1024);
	printf("\n");
	printf("%+d", 1024);
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%+d", -1024);
	printf("\n");
	printf("%+d", -1024);
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%+d", 0);
	printf("\n");
	printf("%+d", 0);
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%+d", INT_MAX);
	printf("\n");
	printf("%+d", INT_MAX);
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%+d", INT_MIN);
	printf("\n");
	printf("%+d", INT_MIN);
  
	i++;
	printf("\n============== %i ================\n", i);
	l = (long int)INT_MAX + 1024;
	_printf("%+d", l);
	printf("\n");
	printf("%+d", l);
	
  i++;
	printf("\n============== %i ================\n", i);
	l = (long int)INT_MIN + 1024;
	_printf("%+d", l);
	printf("\n");
	printf("%+d", l);
  
	i++;
	printf("\n============== %i ================\n", i);
	_printf("There is %+d bytes in %+d KB\n", 1024, 1);
	printf("There is %+d bytes in %+d KB\n", 1024, 1);
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%+d - %+d = %+d\n", 1024, 2048, -1024);
	printf("%+d - %+d = %+d\n", 1024, 2048, -1024);
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%+d + %+d = %+d\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));;
	printf("%+d + %+d = %+d\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));
	
	
	printf("\n");
	
	return (1);
}
