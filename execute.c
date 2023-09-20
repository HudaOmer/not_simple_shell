#include "main.h"

/**
 * execute - function to fork, execute and wait
 * @data: all needed data
 * Return: Nothing on success, -1 on faliure.
 */
void execute(data_t *data)
{
	char *command = NULL, *actual_command = NULL;
	pid_t child_pid;
	int status;
	int execution_status;

	if (data->argv)
	{
		command = data->argv[0];
		actual_command = _which(command);
		if (actual_command == NULL && isatty(STDIN_FILENO))
		{
			print_error(data, "not found\n");
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
					execution_status = execve(actual_command, data->argv, environ);
					if (execution_status == -1 && isatty(STDIN_FILENO))
					{
						perror("Error");
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
