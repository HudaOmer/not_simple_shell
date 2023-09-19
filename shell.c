#include "main.h"

/*
 * shell - function to mimic the unix shell loop
 * @data: the parameter struct
 * @argv: argument vector
 * Return: 0 on success
 */
int shell(data_t *data, char **argv)
{
	ssize_t r = 0;
	int builtin_ret = 0;

	while (builtin_ret != -2)
	{
		clear_data(data);
		if (interactive(data))
			_puts("$ ");
		putc_to_stderr(BUF_FLUSH);

		set_data(data, argv);
		builtin_ret = is_builtin(data);
		if (builtin_ret == -1)
			execute(data);
	
		if (interactive(data))
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
