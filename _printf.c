#include "main.h"
#include<stdarg.h>
#include<stdio.h>
#include<unistd.h>

/**
 * _printf - produces output according to a format
 * @format: character string
 * Return: int
 */

int _printf(const char *format, ...)
{
	int i, count = 0;
	va_list args;
	char *s;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			count++;
		}
		else
		{
			i++;
			if (format[i] == 'c')
			{
				putchar(va_arg(args, int));
				count++;
			}
			else if (format[i] == 's')
			{
				print_string(va_arg(args, char *), &count);
			}
			else if (format[i] == '%')
			{
				putchar('%');
				count = 1;
			}
		}
	}
	va_end(args);
	return (count);
}
