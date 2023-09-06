#include "shell.h"

/**
 * _copy - copying string
 * @end: end of the string
 * @str: copied string
 * Return: null or address
*/

int _copy(char *end, char *str)
{
	int c = 0;

	if (str == NULL || end == NULL)
		return (0);

	while (str[c])
	{
		end[c] = str[c];
		c++;
	}
	end[c] = '\0';

	return (1);
}

