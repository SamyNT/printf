#include "main.h"
/**
 * char_type - converts a char to a string
 * @c: char to convert
 * Return: 2 byte string
 */
char *char_type(va_list c)
{
	char string[2];
	char *p;

	p = string;

	string[0] = va_arg(c, int);
	string[1] = '\0';
	return (p);
}

/**
 * string_type - receives a string and returns it
 * @s: string received
 * Return: entered string
 */

char *string_type(va_list s)
{
	char *string;

	string = va_arg(s, char *);
	if (!string)
		return ("(null)");
	return (string);
}
/**
 * percent_type - returns % character
 * Return: "%"
 */

char *percent_type(void)
{
	char *string;

	string = "%";
	return (string);
}
