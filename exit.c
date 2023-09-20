#include "main.h"


/**
 * no_of_digits - number of digits
 * @i: integer
 * @base: which base
 * Return: number of digits
 */
int no_of_digits(unsigned int i, int base)
{
	int count = 0;

	if (i == 0)
		return (++count);
	while (i > 0)
	{
		i /= base;
		count++;
	}
	return (count);
}

/**
 * _itoa - convert int to string.
 * @n: number
 * Return: String pointer
 */
char *_itoa(int n)
{
	unsigned int n1;
	int lenght = no_of_digits(n, 10);
	char *buffer;

	buffer = malloc(sizeof(char) * (lenght + 1));
	if (buffer == 0)
		return (NULL);

	*(buffer + lenght) = '\0';

	if (n < 0)
	{
		n1 = n * -1;
		buffer[0] = '-';
	}
	else
	{
		n1 = n;
	}

	lenght--;
	do {
		*(buffer + lenght) = (n1 % 10) + '0';
		n1 = n1 / 10;
		lenght--;
	}
	while (n1 > 0)
		;
	return (buffer);
}

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

	str = _itoa(data->line_count);
	length = _strlen(data->file_name) + _strlen(str);
	length += _strlen(data->argv[0]) + _strlen(data->argv[1]) + 23;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(str);
		return (NULL);
	}
	_strcpy(error, data->file_name);
	_strcat(error, ": ");
	_strcat(error, str);
	_strcat(error, ": ");
	_strcat(error, data->argv[0]);
	_strcat(error, ": Illegal number: ");
	_strcat(error, data->argv[1]);
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
	char *error = NULL;
	(void)error;

	if (data->argv[1])
	{
		exit_status = _erratoi(data->argv[1]);
		if (exit_status == -1)
		{
			data->status = 2;
			error = exit_error(data);
			write(STDERR_FILENO, error, _strlen(error));
			return (1);
		}
		data->status = data->err_num = _erratoi(data->argv[1]);
		return (-2);
	}
	data->err_num = -1;
	exit(exit_status);
}
