#include "shell.h"

/**
 * quit_cmd - quiting shell
 * @cmd: command
 * Return: null or address
*/

void quit_cmd(char **cmd)

{
	int c = 0;

	if (cmd[1] == NULL)
	{
		release_array(cmd);
		exit(c);
	}
	else
	{
		c = atoi(cmd[1]);
		release_array(cmd);
		exit(c);
	}
}

