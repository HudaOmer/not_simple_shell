#include "main.h"

/**
 * _exit_shell - exits the shell
 * @line: to compare
 * Return: void
 */
void _exit_shell(char *line)
{
	char *ext = "exit ";
	int i, isequal = 0;


	for (i = 0; ext[i]; i++)
	{
		if (ext[i] == line[i])
			;
		else
		{
			i = 1;
			break;
		}
		ext++;
		line++;
	}
	if (i == 0)
		return;
}
