#include "shell.h"

/**
 * _str_size - size of the string
 * @str: string
 * Return: null or address
*/

int _str_size(char *str)

{
	int c = 0;

	if (str == NULL)
		return (0);

	while (str[c])
		c++;

	return (c);
}

