#include "main.h"
#include <stdio.h>

/**
 * print_string - prints a string and returns number of characters printed
 * @x: string
 * Return: int
 */

void print_string(char *x, int *count )
{
	int i;

	if (x == NULL)
	{
		*x = "";
		putchar(x);
	}
	for (i = 0; x[i] != '\0'; i++)
	{
		putchar(x[i]);
		*count++;
	}
}
