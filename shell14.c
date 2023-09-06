#include "shell.h"

/**
 * _display - displaying output
 * @position: showing the position
 * @argv: argument to values
 * @msg: msg to display
 * Return: null or address
*/

void _display(int position, char **argv, char *msg)

{
	write(position, argv[0], _str_size(argv[0]));
	write(position, msg, _str_size(msg));
}


/**
 * _display_error - displaying errors
 * @position: showing the position
 * @argv: argument to values
 * @cmd: command
 * Return: null or address
*/

void _display_error(int position, char **argv, char *cmd)

{
	write(position, argv[0], _str_size(argv[0]));
	write(position, ": 1: ", 5);
	write(position, cmd,  _str_size(cmd));
	write(position, ":data not found\n", _str_size(":data not found\n"));
}

