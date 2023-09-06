#include "shell.h"

/**
 * _nmbr_value - the number of values
 * @input: getting data input
 * Return: null or void
*/

int _nmbr_value(char *input)

{
	char *delim = " \n";
	char *value;
	int c = 0;

	value = strtok(input, delim);
	if (value != NULL)
	{
		c++;
		value = strtok(NULL, delim);
	}

	return (c);
}

/**
 * store_data - data to be stored
 * @input: input data
 * @argv: argument to value
 * Return: null or address
*/

char **store_data(char *input, char **argv)

{
	char *delim = " \t\r\n", *input_copy = NULL, *value;
	int c = 0, i = 0;
	char **values = NULL;

	c = _str_size(input) + 1;
	input_copy = malloc(c * (sizeof(char)));

	if (input_copy == NULL)
	{
		_display(2, argv, " : failed to give memory");
		return (NULL);
	}

	_copy(input_copy, input);
	c = _nmbr_value(input_copy);
	free(input_copy);
	values = malloc((c + 1) * sizeof(char *));

	if (values == NULL)
	{
		_display(2, argv, " : failed to give memory");
		return (NULL);
	}

	value = strtok(input, delim);
	while (value != NULL)
	{
		values[i] = malloc((_str_size(value) + 1) * sizeof(char));
		if (values == NULL)
		{
			release_array(values);
			_display(2, argv, " : failed to give memory");
			return (NULL);
		}
		_copy(values[i], value);
		value = strtok(NULL, delim);
		i++;
	}
	values[c] = NULL;
	return (values);
}

