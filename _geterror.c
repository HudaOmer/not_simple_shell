#include "main.h"

/**
 * error_exit_shell - error message
 * @data: data needed
 * Return: error message string
 */
char *error_exit_shell(data_t *data)
{
	int length;
	char *error;
	char *ver_str;

	ver_str = _itoa(data->line_count);
	length = _strlen(data->file_name) + _strlen(ver_str);
	length += _strlen(data->argv[0]) + _strlen(data->argv[1]) + 23;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(ver_str);
		return (NULL);
	}
	_strcpy(error, data->file_name);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, data->argv[0]);
	_strcat(error, ": Illegal number: ");
	_strcat(error, data->argv[1]);
	_strcat(error, "\n\0");
	free(ver_str);

	return (error);
}

/**
 * get_error - creates error string
 * @data: data needed
 * @e_val: error value
 * Return: error value
 */
int get_error(data_t *data, int e_val)
{
	char *error;

	switch (e_val)
	{
	case -1:
		error = error_env(data);
		break;
	case 126:
		error = error_path_126(data);
		break;
	case 127:
		error = error_not_found(data);
		break;
	case 2:
		if (_strcmp("exit", data->argv[0]) == 0)
			error = error_exit_shell(data);
		else if (_strcmp("cd", data->argv[0]) == 0)
			error = error_get_cd(data);
		break;
	}

	if (error)
	{
		write(STDERR_FILENO, error, _strlen(error));
		free(error);
	}

	data->status = e_val;
	return (e_val);
}
