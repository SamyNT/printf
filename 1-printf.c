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
	int i, bufflen;
	va_list args;
	char *buffer, *temp_buffer;

	buffer = malloc(sizeof(char) * BUFSIZE);
	bufflen = 0;
	if (format == NULL || buffer == NULL)
		return (-1);
	for (i = 0; i < BUFSIZE; i++)
	{
		buffer[i] = 0;
	}
	va_start(args, format);
	for (i = 0; format[i] != '\0' && format[i] ; i++)
	{
		replace_specifier(format, &i, args, buffer, &bufflen);
		if (bufflen >= BUFSIZE)
		{
			biggerbuffer(buffer, bufflen);
			if (buffer == NULL)
				return (-1);
		}
	}
	va_end(args);
	write(1, buffer, bufflen);
	free(buffer);
	return (bufflen);
}

/**
 * biggerbuffer - creates a bigger buffer in case the current one is too small
 * @buffer: buffer to elongate
 * @bufflen: current buffer size
 * Return: buffer
 *
*/
void biggerbuffer(char *buffer, int bufflen)
{
	int new_bufflen;

	new_bufflen = 2 * bufflen;
	buffer = realloc(buffer, sizeof(char) * new_bufflen);
}

/**
 * replace_specifier - replaces specifier
 *  by corresponding string inside the buffer
 * @buffer: buffer to elongate
 * @bufflen: current buffer size
 * @i:pointer to iteration variable i
 * @format: input string to _printf
 * @args: argument list
 * Return: buffer
 *
*/

void replace_specifier(const char *format, int *i, va_list args,
	 char *buffer, int *bufflen)
{
	char *(*found_type)(va_list);
	char *temp_buffer;
	int templen;

	templen = 0;
	if (format[*i] == '%')
	{
		found_type = get_specifier(format[*i + 1]);
		temp_buffer = (found_type == NULL) ?
			nothing_found(format[*i + 1]) :
			found_type(args);
		templen = _strlen(temp_buffer);
		_strcpy(buffer + *bufflen, temp_buffer);
		*bufflen += templen;
		(*i)++;
	}
	else
	{
		temp_buffer = ctos(format[*i]);
		_strcpy(buffer + *bufflen, temp_buffer);
		(*bufflen)++;
	}
}

