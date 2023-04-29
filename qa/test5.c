#include "main.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
	int i = 3, len, len2;
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%.6d", 102498402);
	printf("\n");
	_printf("%.6d", 102498402);
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%.6d", -102498402);
	printf("\n");
	printf("%.6d", -102498402);
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%6d", 0);
	printf("\n");
	printf("%6d", 0);
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%.6d", 1024);
	printf("\n");
	printf("%.6d", 1024);
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%.6d", -1024);
	printf("\n");
	printf("%.6d", -1024);
  
	i++;
	printf("\n============== %i ================\n", i);
	_printf("In the middle %.6d of a sentence.\n", 1024);
	printf("In the middle %.6d of a sentence.\n", 1024);
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%.0d", 0);
	printf("\n");
	printf("%.0d", 0);
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%.d", 0);
	printf("\n");
	printf("%.d", 0);
	
	printf("/********************************( u )*********************************/");
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%.6u", 102498402);
	printf("\n");
	_printf("%.6u", 102498402);
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%.6u", 0);
	printf("\n");
	printf("%.6u", 0);
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%.6u", 1024);
	printf("\n");
	printf("%.6u", 1024);
  
	i++;
	printf("\n============== %i ================\n", i);
	_printf("In the middle %.6u of a sentence.\n", 1024);
	printf("In the middle %.6u of a sentence.\n", 1024);
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%.0u", 0);
	printf("\n");
	printf("%.0u", 0);
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%.u", 0);
	printf("\n");
	printf("%.u", 0);
	
	
	printf("/********************************( o )*********************************/");
		i++;
	printf("\n============== %i ================\n", i);
	_printf("%.6o", 102498402);
	printf("\n");
	_printf("%.6o", 102498402);
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%.6o", 0);
	printf("\n");
	printf("%.6o", 0);
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%.6o", 1024);
	printf("\n");
	printf("%.6o", 1024);
  
	i++;
	printf("\n============== %i ================\n", i);
	_printf("In the middle %.6o of a sentence.\n", 1024);
	printf("In the middle %.6o of a sentence.\n", 1024);
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%.0o", 0);
	printf("\n");
	printf("%.0o", 0);
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%.o", 0);
	printf("\n");
	printf("%.o", 0);
	
	printf("/********************************( x )*********************************/");
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%.6x", 102498402);
	printf("\n");
	_printf("%.6x", 102498402);
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%.6x", 0);
	printf("\n");
	printf("%.6x", 0);
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%.6x", 1024);
	printf("\n");
	printf("%.6x", 1024);
  
	i++;
	printf("\n============== %i ================\n", i);
	_printf("In the middle %.6x of a sentence.\n", 1024);
	printf("In the middle %.6x of a sentence.\n", 1024);
	printf("\n");
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%.0x", 0);
	printf("\n");
	printf("%.0x", 0);
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%.x", 0);
	printf("\n");
	printf("%.x", 0);
	
	printf("/********************************( s )*********************************/");
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%.6s", "Best School !\n");
	printf("%.6s", "Best School !\n");
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%.6s", "Hi!\n");
	printf("%.6s", "Hi!\n");
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%.0s", "Hi!\n");
	printf("%.0s", "Hi!\n");
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%.s", "Hi!\n");
	printf("%.s", "Hi!\n");
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("In the middle %6s of a sentence.\n", "Hey");
	printf("In the middle %6s of a sentence.\n", "Hey");
	
	printf("/********************************( *d )*********************************/");
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%.*d", 6, 0);
	printf("\n");
	printf("%.*d\n", 6, 0);
	
	
	len = _printf("%.*s", 6, "Best School !\n");
	len2 = printf("%.*s", 6, "Best School !\n");
	printf("\n len : %i\n", len);
	printf("\n len : %i\n", len2);
	
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	return (0);
	
	return (1);
}
