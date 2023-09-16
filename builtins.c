#include "main.h"

/**
 * is_builtin - checkes if the command is a built in and executes the function
 * @argv: Argument Vector
 * @fn: file name
 * Return: nothing
 */
void is_builtin(char **argv, char *fn)
{
	builtin_t builtin[] = {
		/*{ "env", env },*/
		{ "exit", _exit_shell },
		{ NULL, NULL }
	};
	int i;
	bool found;

	found = false;
	for (i = 0; builtin[i].name; i++)
	{
		if (_strcmp(builtin[i].name, argv[0]) == 0)
			found = true;
		break;
	}
	if (found)
		builtin[i].f();
	else
		execute(argv, fn);
}
