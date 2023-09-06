#include "shell.h"

/**
 * begin - starting point of simple shell
 * @argc: argument to counter
 * @argv: argument to values
 * @env: environment variable
 * Return: null or address
*/

int begin(int argc, char **argv, char **env)

{
	char *title = "SHELL";
	char *insert = NULL;
	char **value = NULL;

	(void)argc;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(1, title, 5);

		insert = prompt_input(argv);
		if (insert == NULL)
			continue;

		value = store_data(insert, argv);
		if (value == NULL)
		{
			free(insert);
			continue;
		}
		free(insert);

		run_cmd(value, argv, env);

		release_array(value);
	}

	if (insert != NULL)
		free(insert);

	if (value != NULL)
		release_array(value);
	return (0);
}
