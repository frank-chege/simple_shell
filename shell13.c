#include "shell.h"

/**
 * _concat - concating two strings
 * @end: first string and have the final result.
 * @str: strings
 * Return: null or address
*/

char *_concat(char *end, const char *str)
{
	char *last = end;
	const char *tmp = str;

	while (*last != '\0')
		last++;

	while (*tmp != '\0')
	{
		*last++ = *tmp++;
	}
	*last = '\0';

	return (end);
}

