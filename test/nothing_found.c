#include "main.h"
/**
 * nothing_found - the character after % does not match any
 * specifier
 * @c: charater passed in and to return
 * Return: string with persent and character
 */

char *nothing_found(char c)
{
	char string[3];
	char *p;

	p = string;
	string[0] = '%';
	string[1] = c;
	string[2] = '\0';
	return (p);
}
