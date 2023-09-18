#include "main.h"

/**
 * print_env - prints the environment
 *
 * Return: Always 0.
 */
int print_env(data_t __attribute__((unused))*data)
{
	unsigned int i;

	i = 0;
	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}

	return (0);
}

/**
 * _setenv - sets a new environment variable or updates environ
 * @name: name of variable
 * @value: value of variable
 * @overwrite: 0 or 1
 * Return:  zero
 */
int set_env(char *name, char *value, int overwrite)
{
	int i = 0, len = 0;
	char *new;

	if (!name || !value)
		return (-1);
	while (environ[i])
	{
		len = strlen(name);
		if (strncmp(environ[i], name, len) == 0)
		{
			if (overwrite)
			{
				new = malloc(_strlen(name + _strlen(value) + 2));
				_strcpy(new, name);
				_strcat(new, "=");
				_strcat(new, value);
				environ[i] = new;
				return (0);
			}
			return (0);
		}
		i++;
	}
	new = malloc(_strlen(name + _strlen(value) + 2));
	_strcpy(new, name);
	_strcat(new, "=");
	_strcat(new, value);
	environ[i] = new;
	environ[i + 1] = NULL;
	free(new);
	return (0);
}

/**
 * _setenv - Initialize a new environment variable,
 *  or modify an existing
 *  Return: Always 0
 */
int _setenv(data_t *data)
{
	if (data->argv[1] == NULL || data->argv[2] == NULL)
	{
		printf("Incorrect number of arguements \n");
		return (1);
	}
	if (set_env(data->argv[0], data->argv[1], atoi(data->argv[2])))
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
