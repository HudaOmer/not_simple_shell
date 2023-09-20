#include "main.h"

/**
 * exit_error - generate error message
 * @data: data needed
 * Return: Error message
 */
char *exit_error(data_t *data)
{
	int length;
	char *error;
	char *str;

	str = aux_itoa(data->line_count);
	length = _strlen(data->file_name) + _strlen(str);
	length += _strlen(datash->argv[0]) + _strlen(datash->argv[1]) + 23;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(str);
		return (NULL);
	}
	_strcpy(error, datash->file_name);
	_strcat(error, ": ");
	_strcat(error, str);
	_strcat(error, ": ");
	_strcat(error, datash->argv[0]);
	_strcat(error, ": Illegal number: ");
	_strcat(error, datash->argv[1]);
	_strcat(error, "\n\0");
	free(str);

	return (error);
}

/**
 * _exit_shell - exits the shell
 * @data: all needed data
 * Return: status
 */
int _exit_shell(data_t *data)
{
	int exit_status = 0;

	if (data->argv[1])
	{
		exit_status = _erratoi(data->argv[1]);
		if (exit_status == -1)
		{
			data->status = 2;
			perror(exit_error(data));
			return (1);
		}
		data->status = data->err_num = _erratoi(data->argv[1]);
		return (-2);
	}
	data->err_num = -1;
	exit(exit_status);
}
