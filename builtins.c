#include "main.h"

/**
 * is_builtin - checkes if the command is a built in and executes the function
 * @data: all data needed
 * Return: nothing
 */
void is_builtin(data_t *data)
{
	builtin_t builtin[] = {
		{ "env", print_env },
		{ "exit", _exit_shell },
		{ "setenv", _setenv},
		{ "unsetenv", _unsetenv},
		{ NULL, NULL }
	};
	int i;
	bool found;

	found = false;
	for (i = 0; builtin[i].name; i++)
	{
		if (_strcmp(builtin[i].name, data->argv[0]) == 0)
		{
			data->line_count++;
			found = true;
			break;
		}
	}
	if (found)
		builtin[i].f(data);
	else
		execute(data);
}
