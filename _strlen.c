#include "main.h"
/**
 * _strlen - main function
 * Description: returns length of string
 *
 *
 *@s: input string
 * Return: length of string
 */
int _strlen(char *s)
{
	int count;

	count = 0;
	while (*s != '\0')
	{
		count++;
		s++;
	}
	return (count);
}
