#include "main.h"

/**
 * is_digit - checks if a string contains a non-digit char
 * @s: string to be evaluated
 *
 * Return: 0 if a non-digit is found, 1 otherwise
 */
int is_digit(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

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
	unsigned int ustatus;
	int isdigit;
	int str_len;
	int big_number;

	if (data->argv[1] != NULL)
	{
		ustatus = _atoi(data->argv[1]);
		isdigit = is_digit(data->argv[1]);
		str_len = _strlen(data->argv[1]);
		big_number = ustatus > (unsigned int)INT_MAX;
		if (!isdigit || str_len > 10 || big_number)
		{
			get_error(data, 2);
			data->status = 2;
			return (1);
		}
		data->status = (ustatus % 256);
	}
	exit(data->status);
}
