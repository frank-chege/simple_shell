#include "shell.h"

/**
 * run_cmd - running commands.
 * @value: argument to be execute.
 * @argv: argument to values.
 * @env: environment variable.
 * Return: null or address.
*/

void run_cmd(char **value, char **argv, char **env)

{
	pid_t run;
	int c;

	if (value == NULL || value[0] == NULL)
	return;

	if (value[0][0] != '.' && value[0][0] != '/')
	{
		if (_missing(value, env))
			return;
		else if (!display_path(value, env))
		{
			_display_error(2, argv, value[0]);
			return;
		}
	}

	run = fork();
	if (run == -1)
	{
		_display(2, argv, ":creating process failed\n");
		return;
	}

	if (run == 0)
	{
		if (execve(value[0], value, env) == -1)
		{
			_display_error(2, argv, value[0]);
			release_array(value);
			exit(1);
		}
	}
	else
	{
		do {
			waitpid(run, &c, WUNTRACED);
		} while (!WIFEXITED(c) && !WIFSIGNALED(c));
	}
}

