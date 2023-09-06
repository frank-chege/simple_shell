#include "shell.h"

/**
 * _compare - comparing two strings
 * @str1: string one
 * @str2: string two
 * @sz: size of strings
 * Return: null or address
*/

int _compare(char *str1, char *str2, size_t sz)
{
	size_t c = 0;

	for (c = 0 ; str1[c] && str2[c] && c < sz ; c++)
	{
		if (str1[c] != str2[c])
		{
			return (-1);
		}
	}

	if (c == sz)
		return (0);

	return (-1);
}

