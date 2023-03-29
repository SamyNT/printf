#include "main.h"
/**
 * get_specifier - Identifies which specifier was passed to printf
 * @s: We check if this character is a specifier
 * Return: pointer function of char type, specifier matched
 */

char *(*get_specifier(char s))(va_list)
{
	int i;
	s_types valid_types[] = {
		{"c", char_type},
		{"s", string_type},
		{"%", percent_type},
		{NULL, NULL}
	};
	for (i = 0; valid_types[i].type; i++)
	{
		if (s == *valid_types[i].type)
		{
			return (valid_types[i].f);
		}
	}
	return (NULL);
}
/**
 * ctos - converts a character to a string
 * @c: character to convert
 * Return: pointer to string
 */
char *ctos(char c)
{
	char string[1];
	char *p;

	p = string;
	string[0] = c;
	return (p);
}

