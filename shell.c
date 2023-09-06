#include "shell.h"

/**
 * main - where the program starts
 * @argc: argument to counter
 * @argv: argument to values
 * @env: environment variable
 * Return: null or address
*/

int main(int argc, char **argv, char **env)

{
	int start_code = begin(argc, argv, env);

	return (start_code);
}

