#include "main.h"

/**
 * _exit_shell - exits the shell
 * @argv: Argument Vector
 * @fn: file_name
 * Return: void
 */
void _exit_shell(char **argv, char *fn)
{
	if (_strcmp(argv[0], "exit") == 0)
	{
		exit(0);
	}
	else
	{
		if (_strcmp(argv[0], "env") == -1)
		{
			env();
		}
		else
		{
		/* execute the command */
		execute(argv, fn);
		}
	}
}
