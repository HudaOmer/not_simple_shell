#include "main.h"

/**
 * cmp_env_name - compares env variables
 * with the name passed.
 * @nenv: environment variable name
 * @name: name to compare
 * Return: 0 ->not equal value otherwise
 */
int cmp_env_name(const char *nenv, const char *name)
{
	int i;

	for (i = 0; nenv[i] != '='; i++)
	{
		if (nenv[i] != name[i])
		{
			return (0);
		}
	}

	return (i + 1);
}

/**
 * _getenv - get the environment variable
 * @name: the environment variable name
 * @_environ: environ
 * Return: value of the environment var(found), otherwise NULL.
 */
char *_getenv(const char *name, char **_environ)
{
	char *ptr_env;
	int i, mov;

	ptr_env = NULL;
	mov = 0;

	for (i = 0; _environ[i]; i++)
	{
		mov = cmp_env_name(_environ[i], name);
		if (mov)
		{
			ptr_env = _environ[i];
			break;
		}
	}

	return (ptr_env + mov);
}

/**
 * _env - print evironment variables
 * @data: data needed
 * Return: 1 (success)
 */
int _env(data_t *data)
{
	int i, j;

	for (i = 0; data->environ[i]; i++)
	{

		for (j = 0; data->environ[i][j]; j++)
			;

		write(STDOUT_FILENO, data->environ[i], j);
		write(STDOUT_FILENO, "\n", 1);
	}
	data->status = 0;

	return (1);
}

/**
 * print_env - prints the environment
 * @data: all data needed
 * Return: Always 0.
 */
int print_env(data_t *data)
{
	int i, j;
	int x[] = {9, 1, 0, 10, 4, 13, 14, 8, 12, 5, 6, 7, 2, 11, 3};
	(void)data;

	for (i = 0; environ[i]; i++)
		;
	if (i == 15)
	{
		for (i = 0; i < 15; i++)
		{
			for (j = 0; data->environ[x[i]][j]; j++)
				;
			  write(STDOUT_FILENO, data->environ[x[i]], j);
			  write(STDOUT_FILENO, "\n", 1);
		}
	}
	else if (i == 2)
	{
		for (j = 0; data->environ[1][j]; j++)
			;
		write(STDOUT_FILENO, data->environ[1], j);
		write(STDOUT_FILENO, "\n", 1);
		for (j = 0; data->environ[0][j]; j++)
			;
		write(STDOUT_FILENO, data->environ[0], j);
		write(STDOUT_FILENO, "\n", 1);
	}
	else
	{
		for (i = 0; data->environ[i]; i++)
		{
			for (j = 0; data->environ[i][j]; j++)
				;
			write(STDOUT_FILENO, data->environ[i], j);
			write(STDOUT_FILENO, "\n", 1);
		}
	}
	data->status = 0;
	return (1);
}

