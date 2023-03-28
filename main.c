#include<stdio.h>
#include"main.h"

int main()
{
	char *x = "ghh";
	_printf(x);
	printf("\n");
	_printf("%s", x);
	printf("\n");
	_printf("go %c", 'y');
	return (0);
}

