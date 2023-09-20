#include "main.h"

/**
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

/**
 * _unsetenv - removes an environment variable using unset_env
 * @data: the parameter struct
 * Return: 0 sucess 1 otherwise
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
int pop_env(data_t *data)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	data->env = node;
	return (0);
}
