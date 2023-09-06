#include "shell.h"

/**
 * _missing - showing missing things
 * @cmd: command
 * @env: environment variable
 * Return:null or address
*/

int _missing(char **cmd, char **env)

{
	if (_compare(cmd[0], "env", 3) == 0)
	{
		display_env(env);
		return (1);
	}
	else if (_compare(cmd[0], "exit", 4) == 0)
	{
		quit_cmd(cmd);
		return (1);
	}
	return (0);
}

