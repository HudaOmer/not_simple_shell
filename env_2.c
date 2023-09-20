#include "main.h"

/**
 * copy_info - copies info
 * @name: env or alias name
 * @value: env or alias name
 * Return: new env or alias
 */
char *copy_info(char *name, char *value)
{
	char *new;
	int len_name, len_value, len;

	len_name = _strlen(name);
	len_value = _strlen(value);
	len = len_name + len_value + 2;
	new = malloc(sizeof(char) * (len));
	_strcpy(new, name);
	_strcat(new, "=");
	_strcat(new, value);
	_strcat(new, "\0");

	return (new);
}

/**
 * set_env - sets a new environment variable
 * @name: environment variable anme
 * @value: environment variable value
 * @data: data needed
 * Return: void
 */
void set_env(char *name, char *value, data_t *data)
{
	int i;
	char *var_env, *name_env;

	for (i = 0; data->environ[i]; i++)
	{
		var_env = _strdup(data->environ[i]);
		name_env = _strtok(var_env, "=");
		if (_strcmp(name_env, name) == 0)
		{
			free(data->environ[i]);
			data->environ[i] = copy_info(name_env, value);
			free(var_env);
			return;
		}
		free(var_env);
	}

	data->environ = _reallocdp(data->environ, i, sizeof(char *) * (i + 2));
	data->environ[i] = copy_info(name, value);
	data->environ[i + 1] = NULL;
}

/**
 * _setenv - compares env variables names
 * @data: needed
 * Return: 1 (success)
 */
int _setenv(data_t *data)
{

	if (data->argv[1] == NULL || data->argv[2] == NULL)
	{
		get_error(data, -1);
		return (1);
	}

	set_env(data->argv[1], data->argv[2], data);

	return (1);
}

/**
 * _unsetenv - remove an environment variable
 * @data: data needed
 * Return: 1 on success.
 */
int _unsetenv(data_t *data)
{
	char **realloc_environ;
	char *var_env, *name_env;
	int i, j, k;

	if (data->argv[1] == NULL)
	{
		get_error(data, -1);
		return (1);
	}
	k = -1;
	for (i = 0; data->environ[i]; i++)
	{
		var_env = _strdup(data->environ[i]);
		name_env = _strtok(var_env, "=");
		if (_strcmp(name_env, data->argv[1]) == 0)
		{
			k = i;
		}
		free(var_env);
	}
	if (k == -1)
	{
		get_error(data, -1);
		return (1);
	}
	realloc_environ = malloc(sizeof(char *) * (i));
	for (i = j = 0; data->environ[i]; i++)
	{
		if (i != k)
		{
			realloc_environ[j] = data->environ[i];
			j++;
		}
	}
	realloc_environ[j] = NULL;
	free(data->environ[k]);
	free(data->environ);
	data->environ = realloc_environ;
	return (1);
}
