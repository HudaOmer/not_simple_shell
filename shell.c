#include "main.h"

/**
 * shell - function to mimic the unix shell loop
 * @data: the parameter struct
 * @argv: argument vector
 * Return: 0 on success
 */
int shell(data_t *data, char **argv)
{
	ssize_t r = 0;
	int builtin_ret = 0;
	char **av = argv;

	while (r != -1 && builtin_ret != -2)
	{
		clear_data(data);
		if (interactive(data))
			_puts("$ ");
		_eputchar(BUF_FLUSH);
		r = get_input(data);
		if (r != -1)
		{
			set_info(data, av);
			builtin_ret = find_builtin(data);
			if (builtin_ret == -1)
				find_cmd(data);
		}
		else if (interactive(data))
			_putchar('\n');
		free_data(data, 0);
	}
	write_history(data);
	free_data(data, 1);
	if (!interactive(data) && data->status)
		exit(data->status);
	if (builtin_ret == -2)
	{
		if (data->err_num == -1)
			exit(data->status);
		exit(data->err_num);
	}
	return (builtin_ret);
}
