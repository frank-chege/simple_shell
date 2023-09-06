#include "shell.h"

/**
 * display_path - showing the route
 * @value: data to be executed
 * @env: environment variable
 * Return: null or address
*/

int display_path(char **value, char **env)

{
	char *route = _show_env(env, "PATH");
	char *dir, *route_dir;
	char *cmd;
	struct stat dp;
	int c;

	if (route == NULL)
		return (0);
	c = _str_size(route) + 1;
	route_dir = malloc(c * (sizeof(char)));
	if (route_dir == NULL)
		return (0);
	_copy(route_dir, route);

	dir = strtok(route_dir, ":=");

	while (dir != NULL)
	{
		cmd = malloc(_str_size(dir) + _str_size(value[0]) + 2);
		if (!cmd)
		{
			free(route_dir);
			return (0);
		}
		_copy(cmd, dir);
		_concat(cmd, "/");
		_concat(cmd, value[0]);
		if (stat(cmd, &dp) == 0)
		{
			free(value[0]);
			value[0] = cmd;
			free(route_dir);
			return (1);
		}
		free(cmd);
		dir = strtok(NULL, ":=");
	}
	free(route_dir);

	return (0);
}

