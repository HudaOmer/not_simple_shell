#include "main.h"

/**
 * execute - function to fork, execute and wait
 * @argv: Argument Vector
 * @file_name: name of the file
 * Return: Nothing on success, -1 on faliure.
 */
void execute(char **argv, char *file_name)
{
	char *command = NULL, *actual_command = NULL;
	pid_t child_pid;
	int status;

	if (argv)
	{
		command = argv[0];
		actual_command = _which(command);
		if (actual_command == NULL && isatty(STDIN_FILENO))
		{
			printf("%s: %s: not found\n", file_name, argv[0]);
		}
		else
		{
			child_pid = fork();
			if (child_pid == -1)
			{
				perror("Error");
			}
			else
			{
				if (child_pid == 0)
				{

					if (execve(actual_command, argv, environ) == -1 && isatty(STDIN_FILENO))
					{
						printf("%s: %s: not found\n", file_name, argv[0]);
					};
				}
				else
				{
					wait(&status);
				}
			}
		}
	}

}
