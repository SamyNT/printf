#include "main.h"

/**
 * _printf - reproduces the behaviour of the printf
 * function
 *
 * @format: holds the input string
 *
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	int i, templen, bufflen;
	va_list args;
	char buffer[BUFSIZE], *temp_buffer;
	char *(*found_type)(va_list);

	bufflen = 0;
	templen = 0;
	for (i = 0; i < BUFSIZE; i++)
	{
		buffer[i] = 0;
	}
	va_start(args, format);
	for (i = 0; format[i] != '\0' && format[i] ; i++)
	{
		if (format[i] == '%')
		{
			found_type = get_specifier(format[i + 1]);
			temp_buffer = found_type(args);
			templen = _strlen(temp_buffer);
			_strcpy(buffer + bufflen, temp_buffer);
			bufflen += templen;
			i++;
		}
		else
		{
			temp_buffer = ctos(format[i]);
			_strcpy(buffer + bufflen, temp_buffer);
			bufflen++;
		}


	}
	va_end(args);
	write(1, buffer, bufflen);
	return (bufflen);
}
