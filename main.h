#ifndef MAIN_H
#define MAIN_H

#define BUFSIZE 1025
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
/**
 * struct specifiers - structure to verify a character is a specifier
 * @type: Type of specifier
 * @f: pointer to function called when specifier is found
 */

typedef struct specifiers
{
	char *type;
	char *(*f)();
} s_types;

int _printf(const char *format, ...);
char *(*get_specifier(char s))(va_list);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);

char *char_type(va_list c);
char *string_type(va_list s);
char *percent_type(void);
char *ctos(char c);
#endif
