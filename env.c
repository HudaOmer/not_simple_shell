#include "main.h"

/**
 * print_env - prints the environment
 * @data: all data needed
 * Return: Always 0.
 */
int print_env(data_t *data)
{
	print_list_str(data->env);
	return (0);
}

/**
 * set_env - sets a new environment variable or updates environ
 * @name: name of variable
 * @value: value of variable
 * @overwrite: 0 or 1
 * Return:  zero
 */
int set_env(data_t *data, char*name, char *value, int overwrite)
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
			if(!new)
				return(1);
			_strcpy(new, name);
			_strcat(new, "=");
			_strcat(new, value);
			if(overwrite)
			{
				node->str = new;
				data->env_changed = 1;
			}
			return (0);
		}
		node = node->next;
	}
	new = malloc(_strlen(name + _strlen(value) + 2));
	if(!new)
		return(1);
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

/*
 * unset_env - removes an environment variable
 * @data: the parameter struct
 * @name: name of variable to be removed
 *
 * Return: 1 upon deletion, 0 otherwise
 */
int unset_env(data_t *data, char *name)
{
	size_t index = 0;
	char *p;
	list_t *node = data->env;

	if (!node || !name)
		return (0);

	while (node)
	{
		p = _startwith(node->str, name);
		if (p && *p == '=')
		{
			data->env_changed = delete_node_at_index(&(data->env), index);
			index = 0;
			node = data->env;
			continue;
		}
		node = node->next;
		index++;
	}
	return (data->env_changed);
}

/*
 * _unsetenv - removes an environment variable using unset_env
 * @data: the parameter struct
 *
 * Retrun: 0
 */
int _unsetenv(data_t *data)
{
	int i;

	if (data->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= data->argc; i++)
		unset_env(data, data->argv[i]);

	return (0);
}

/**
 * pop_env - populates env linked list
 * @data: the parameters struct
 * Return: Always 0
 */
int pop_env(data *data)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	data->env = node;
	return (0);
}
