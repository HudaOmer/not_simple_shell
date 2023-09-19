#include "main.h"

/**
 * _exit_shell - exits the shell
 * @data: all needed data
 * Return: status
 */
int _exit_shell(data_t *data)
{
	int exit_status;

	if (data->argv[1])
	{
		exit_status = _erratoi(data->argv[1]);
		if (exit_status == -1)
		{
			data->status = 2;
			print_error(data, "Illegal number: ");
			_eputs(data->argv[1]);
			putc_to_stderr('\n');
			return (1);
		}
		data->err_num = _erratoi(data->argv[1]);
		return (-2);
	}
	data->err_num = -1;
	exit(0);
}
