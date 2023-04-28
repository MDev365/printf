#include "main.h"
#include <stdio.h>

int main(void)
{
	char *str;
	int i = 3;
	
	i++;
	_printf("\n============== %i ================\n", i);
	_printf("Let's print a simple sentence.\n");
	printf("Let's print a simple sentence.\n");
	
	i++;
	_printf("\n============== %i ================\n", i);
	_printf("%c", 'S');
	printf("%c", 'S');
	
	i++;
	_printf("\n============== %i ================\n", i);
	_printf("A char inside a sentence: %c. Did it work?\n", 'F');
	printf("A char inside a sentence: %c. Did it work?\n", 'F');
	
	i++;
	_printf("\n============== %i ================\n", i);
	_printf("Let'see if the cast is correctly done: %c. Did it work?\n", 48);
	printf("Let'see if the cast is correctly done: %c. Did it work?\n", 48);
	
	i++;
	_printf("\n============== %i ================\n", i);
	_printf("%s", "This sentence is retrieved from va_args!\n");
	printf("%s", "This sentence is retrieved from va_args!\n");
	
	i++;
	_printf("\n============== %i ================\n", i);
	_printf("Complete the sentence: You %s nothing, Jon Snow.\n", "know");
	printf("Complete the sentence: You %s nothing, Jon Snow.\n", "know");
	
	i++;
	_printf("\n============== %i ================\n", i);
	_printf("Complete the sentence: You %s nothing, Jon Snow.\n", (char *)0);
	printf("Complete the sentence: You %s nothing, Jon Snow.\n", (char *)0);
	
	i++;
	_printf("\n============== %i ================\n", i);
	_printf("%c%cth %s%s a%cg%s: Y%sou %s no%ching%s Snow.%c", 'W', 'i', "some ", "more", 'r', "s", "", "know", 't', ", Jon", '\n');
	printf("%c%cth %s%s a%cg%s: Y%sou %s no%ching%s Snow.%c", 'W', 'i', "some ", "more", 'r', "s", "", "know", 't', ", Jon", '\n');
	
	i++;
	_printf("\n============== %i ================\n", i);
	_printf("%%");
	printf("%%");
	
	i++;
	_printf("\n============== %i ================\n", i);
	_printf("Should print a single percent sign: %%\n");
	printf("Should print a single percent sign: %%\n");
	
	i++;
	_printf("\n============== %i ================\n", i);
	_printf("%s%c%c%c%s%%%s%c", "Loading ", '.', '.', '.', " 99", " Please wait", '\n');
	printf("%s%c%c%c%s%%%s%c", "Loading ", '.', '.', '.', " 99", " Please wait", '\n');
	
	i++;
	_printf("\n============== %i ================\n", i);
	_printf("css%ccs%scscscs", 'T', "Test");
	printf("css%ccs%scscscs", 'T', "Test");
	
	i++;
	_printf("\n============== %i ================\n", i);
	str = "Big string";
	_printf(str);
	_printf(str);
	
	i++;
	_printf("\n============== %i ================\n", i);
	_printf("man gcc:\n%s", str);
	printf("man gcc:\n%s", str);
	
	i++;
	_printf("\n============== %i ================\n", i);
	_printf(NULL);
	printf(NULL);
	
	i++;
	_printf("\n============== %i ================\n", i);
	_printf("%c", '\0');
	printf("%c", '\0');
	
	_printf("%");
	printf("%");
	
	_printf("%!\n");
	printf("%!\n");
	
	_printf("%K\n");
	printf("%K\n");
	
	return (1);
}
