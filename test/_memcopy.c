#include "main.h"

/**
 * _memcpy - main function
 * Description: fills the first n adresses of a string with a
 * constant character c
 *
 * @dest: string to be changed
 * @src: string to be copied
 * @n: number of bytes to filled by c
 *
 * Return: A pointer to the memory area dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i = 0;
	unsigned int j = 0;

	while (dest[i] != '\0')
		i++;
	for (j = 0 ; j <= n - 1; j++)
	{
		dest[i] = src[j];
		i++;
	}
	return (dest);
}
