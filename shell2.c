#include "shell.h"

/**
 * prompt_input - prompts shell file to be executed
 * @argv: argument to values
 * Return: null or address;
*/

char *prompt_input(char **argv)

{
	char *dash = NULL;
	size_t c = 0;
	ssize_t str;

	str =  getline(&dash, &c, stdin);
	if (str == -1)
	{
		if (feof(stdin))
		{
			free(dash);
			exit(0);
		}
		else
		{
			_display(2, argv, " :input cannot be read\n");
			free(dash);
			return (NULL);
		}
	}

	if (dash[str - 1] == '\n')
		dash[str - 1] = '\0';

	return (dash);
}

