#include "main.h"
#include <stdio.h>

int main(void)
{
	char *str;
	int i = 3;
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("Let's print a simple sentence.\n");
	printf("Let's print a simple sentence.\n");
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%c", 'S');
	printf("%c", 'S');
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("A char inside a sentence: %c. Did it work?\n", 'F');
	printf("A char inside a sentence: %c. Did it work?\n", 'F');
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("Let'see if the cast is correctly done: %c. Did it work?\n", 48);
	printf("Let'see if the cast is correctly done: %c. Did it work?\n", 48);
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%s", "This sentence is retrieved from va_args!\n");
	printf("%s", "This sentence is retrieved from va_args!\n");
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("Complete the sentence: You %s nothing, Jon Snow.\n", "know");
	printf("Complete the sentence: You %s nothing, Jon Snow.\n", "know");
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("Complete the sentence: You %s nothing, Jon Snow.\n", (char *)0);
	printf("Complete the sentence: You %s nothing, Jon Snow.\n", (char *)0);
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%c%cth %s%s a%cg%s: Y%sou %s no%ching%s Snow.%c", 'W', 'i', "some ", "more", 'r', "s", "", "know", 't', ", Jon", '\n');
	printf("%c%cth %s%s a%cg%s: Y%sou %s no%ching%s Snow.%c", 'W', 'i', "some ", "more", 'r', "s", "", "know", 't', ", Jon", '\n');
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%%");
	printf("%%");
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("Should print a single percent sign: %%\n");
	printf("Should print a single percent sign: %%\n");
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%s%c%c%c%s%%%s%c", "Loading ", '.', '.', '.', " 99", " Please wait", '\n');
	printf("%s%c%c%c%s%%%s%c", "Loading ", '.', '.', '.', " 99", " Please wait", '\n');
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("css%ccs%scscscs", 'T', "Test");
	printf("css%ccs%scscscs", 'T', "Test");
	
	i++;
	printf("\n============== %i ================\n", i);
	str = "Big string";
	_printf(str);
	_printf(str);
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("man gcc:\n%s", str);
	printf("man gcc:\n%s", str);
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf(NULL);
	printf(NULL);
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%c", '\0');
	printf("\n%c", '\0');
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("printf_ : %");
	printf("\nprintf : %");
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("printf_ : %!\n");
	printf("printf : %!\n");
	
	i++;
	printf("\n============== %i ================\n", i);
	_printf("%K\n");
	printf("%K\n");
	
	return (1);
}
