#include "main.h"

/**
 * clear_data - initializes data_t struct
 * @data: struct address
 */
void clear_data(data_t *data)
{
	data->line = NULL;
	data->argv = NULL;
	data->path = NULL;
	data->argc = 0;
}

/**
 * set_data - initializes data_t struct
 * @data: struct address
 * @av: argument vector
 */
void set_data(data_t *data, char **av)
{
	int i = 0;

	data->file_name = av[0];
	if (data->line)
	{
		data->argv = _strtow(data->line, " \t");
		if (!data->argv)
		{

			data->argv = malloc(sizeof(char *) * 2);
			if (data->argv)
			{
				data->argv[0] = _strdup(data->line);
				data->argv[1] = NULL;
			}
		}
		for (i = 0; data->argv && data->argv[i]; i++)
			;
		data->argc = i;
/*
		replace_alias(data);
		replace_vars(data);
*/
	}
}

/**
 * free_data - frees data_t struct fields
 * @data: struct address
 * @all: true if freeing all fields
 */
void free_data(data_t *data, int all)
{
	_freess(data->argv);
	data->argv = NULL;
	data->path = NULL;
	if (all)
	{
		if (!data->cmd_buf)
			free(data->line);
		/*if (data->env)
			free_list(&(data->env));
		if (data->history)
			free_list(&(data->history));
		if (data->alias)
			free_list(&(data->alias));*/
		_freess(data->environ);
			data->environ = NULL;
		_freenull((void **)data->cmd_buf);
		if (data->readfd > 2)
			close(data->readfd);
		_putchar(BUF_FLUSH);
	}
}
