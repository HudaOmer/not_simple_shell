#include "main.h"

/**
 * is_builtin - checkes if the command is a built in and executes the function
 * @data: all data needed
 * Return: nothing
 */
int is_builtin(data_t *data)
{
	builtin_t builtin[] = {
		{ "env", print_env },
		{ "exit", _exit_shell },
		{ "setenv", _setenv},
		{ "unsetenv", _unsetenv},
		{ NULL, NULL }
	};
	int i;
	int ret_val;

	for (i = 0; builtin[i].name; i++)
	{
		if (_strcmp(builtin[i].name, data->argv[0]) == 0)
		{
			ret_val = builtin[i].f(data);
			break;
		}
	}
	data->line_count++;
	if (found)
		builtin[i].f(data);
	else
		execute(data);
	return(ret_val);
}
