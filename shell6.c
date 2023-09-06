#include "shell.h"

/**
 * _show_env - showing the environment
 * @env: environment
 * @cmd: command
 * Return: null or address
*/

char *_show_env(char **env, char *cmd)

{
	int c = 0;
	int sz = _str_size(cmd);

	for (c = 0; env[c]; c++)
	{
		if (_compare(cmd, env[c], sz) == 0)
		return (env[c]);
	}
	return (NULL);
}

/**
 * display_env - display environment
 * @env: environment
 * Return: null or address
*/

void display_env(char **env)
{
	char **c = env;

	while (*c != NULL)
	{
		write(1, *c, _str_size(*c));
		write(1, "\n", 1);
		c++;
	}
}

