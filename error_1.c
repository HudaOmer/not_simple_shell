#include "main.h"

/**
 * strcat_cd - concatenate the message for cd error
 * @data: data needed
 * @msg: message
 * @error: output
 * @ver_str: counter lines
 * Return: error message string
 */
char *strcat_cd(data_t *data, char *msg, char *error, char *ver_str)
{
	char *illegal_flag;

	_strcpy(error, data->file_name);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, data->argv[0]);
	_strcat(error, msg);
	if (data->argv[1][0] == '-')
	{
		illegal_flag = malloc(3);
		illegal_flag[0] = '-';
		illegal_flag[1] = data->argv[1][1];
		illegal_flag[2] = '\0';
		_strcat(error, illegal_flag);
		free(illegal_flag);
	}
	else
	{
		_strcat(error, data->argv[1]);
	}

	_strcat(error, "\n");
	_strcat(error, "\0");
	return (error);
}

/**
 * error_get_cd - error message for cd command
 * @data: data needed
 * Return: error string
 */
char *error_get_cd(data_t *data)
{
	int length, len_id;
	char *error, *ver_str, *msg;

	ver_str = _itoa(data->line_count);
	if (data->argv[1][0] == '-')
	{
		msg = ": Illegal option ";
		len_id = 2;
	}
	else
	{
		msg = ": can't cd to ";
		len_id = _strlen(data->argv[1]);
	}

	length = _strlen(data->file_name) + _strlen(data->argv[0]);
	length += _strlen(ver_str) + _strlen(msg) + len_id + 5;
	error = malloc(sizeof(char) * (length + 1));

	if (error == 0)
	{
		free(ver_str);
		return (NULL);
	}

	error = strcat_cd(data, msg, error, ver_str);

	free(ver_str);

	return (error);
}

/**
 * error_not_found - error message for command not found
 * @data: data needed
 * Return: error string
 */
char *error_not_found(data_t *data)
{
	int length;
	char *error;
	char *ver_str;

	ver_str = _itoa(data->line_count);
	length = _strlen(data->file_name) + _strlen(ver_str);
	length += _strlen(data->argv[0]) + 16;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(error);
		free(ver_str);
		return (NULL);
	}
	_strcpy(error, data->file_name);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, data->argv[0]);
	_strcat(error, ": not found\n");
	_strcat(error, "\0");
	free(ver_str);
	return (error);
}

/**
 * error_env - error message
 * @data: data needed
 * Return: error message
 */
char *error_env(data_t *data)
{
	int length;
	char *error;
	char *ver_str;
	char *msg;

	ver_str = _itoa(data->line_count);
	msg = ": Unable to add/remove from environment\n";
	length = _strlen(data->file_name) + _strlen(ver_str);
	length += _strlen(data->argv[0]) + _strlen(msg) + 4;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(error);
		free(ver_str);
		return (NULL);
	}

	_strcpy(error, data->file_name);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, data->argv[0]);
	_strcat(error, msg);
	_strcat(error, "\0");
	free(ver_str);

	return (error);
}
/**
 * error_path_126 -path and failure denied permission
 * @data: data needed
 * Return: The error string
 */
char *error_path_126(data_t *data)
{
	int length;
	char *ver_str;
	char *error;

	ver_str = _itoa(data->line_count);
	length = _strlen(data->file_name) + _strlen(ver_str);
	length += _strlen(data->argv[0]) + 24;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(error);
		free(ver_str);
		return (NULL);
	}
	_strcpy(error, data->file_name);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, data->argv[0]);
	_strcat(error, ": Permission denied\n");
	_strcat(error, "\0");
	free(ver_str);
	return (error);
}
