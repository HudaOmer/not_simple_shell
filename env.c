#include "main.h"

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

/**
 * set_env - sets a new environment variable or updates environ
 * @data: all data needed
 * @name: name of variable
 * @value: value of variable
 * @overwrite: 0 or 1
 * Return:  zero
 */
int set_env(data_t *data, char *name, char *value, int overwrite)
{
	char *var_p;
	char *new = NULL;
	list_t *node;

	if (!name || !value)
		return (-1);
	node = data->env;
	while (node)
	{
		var_p = _startwith(node->str, name);
		if (var_p && *var_p == '=')
		{
			free(node->str);
			new = malloc(_strlen(name + _strlen(value) + 2));
			if (!new)
				return (1);
			_strcpy(new, name);
			_strcat(new, "=");
			_strcat(new, value);
			if (overwrite)
			{
				node->str = new;
				data->env_changed = 1;
			}
			return (0);
		}
		node = node->next;
	}
	new = malloc(_strlen(name + _strlen(value) + 2));
	if (!new)
		return (1);
	_strcpy(new, name);
	_strcat(new, "=");
	_strcat(new, value);
	add_node_end(&(data->env), new, 0);
	add_node_end(&(data->env), NULL, 0);
	free(new);
	data->env_changed = 1;
	return (0);
}

/**
 * _setenv - Initialize a new environment variable,
 *  or modify an existing using set_env
 * @data: all data needed
 * Return: on success 0 and 1 on error
 */
int _setenv(data_t *data)
{
	if (data->argv[1] == NULL || data->argv[2] == NULL)
	{
		_eputs("Incorrect number of arguements \n");
		return (1);
	}
	if (set_env(data, data->argv[0], data->argv[1], atoi(data->argv[2])))
		return (0);
	return (1);
}

/**
 * _getenv - gets the value of an environ variable
 * @data: the prarmeter struct
 * @name: env variable name
 *
 * Return: the value
 */
char *_getenv(data_t *data, const char *name)
{
	list_t *node = data->env;
	char *p;

	while (node)
	{
		p = _startwith(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}
