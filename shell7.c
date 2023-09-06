#include "shell.h"

/**
 * release_array - array to be released
 * @arr: array
 * Return: null or address
*/

void release_array(char **arr)
{
	int c = 0;

	if (arr == NULL)
		return;

	while (arr[c] != NULL)
	{
		free(arr[c]);
		c++;
	}
	free(arr);
}

