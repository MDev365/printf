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
	
	printf("/********************************( u )*********************************/");
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%6u", 102498402);
	printf("\n");
	_printf("%6u", 102498402);
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%6u", 0);
	printf("\n");
	printf("%6u", 0);
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%6u", 1024);
	printf("\n");
	printf("%6u", 1024);
  
	i++;
	printf("\n============== %i ================\n", i);
	_printf("In the middle %6u of a sentence.\n", 1024);
	printf("\n");
	printf("In the middle %6u of a sentence.\n", 1024);
	
	printf("/********************************( o )*********************************/");
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%6o", 102498402);
	printf("\n");
	_printf("%6o", 102498402);
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%6o", 0);
	printf("\n");
	printf("%6o", 0);
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%6o", 1024);
	printf("\n");
	printf("%6o", 1024);
  
	i++;
	printf("\n============== %i ================\n", i);
	_printf("In the middle %6o of a sentence.\n", 1024);
	printf("\n");
	printf("In the middle %6o of a sentence.\n", 1024);
	
	printf("/********************************( x )*********************************/");
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%6x", 102498402);
	printf("\n");
	_printf("%6x", 102498402);
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%6x", 0);
	printf("\n");
	printf("%6x", 0);
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%6x", 1024);
	printf("\n");
	printf("%6x", 1024);
  
	i++;
	printf("\n============== %i ================\n", i);
	_printf("In the middle %6x of a sentence.\n", 1024);
	printf("\n");
	printf("In the middle %6x of a sentence.\n", 1024);
	printf("\n");
	
	return (1);
}
