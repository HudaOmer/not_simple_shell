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
	int execution_status;

	if (data->argv)
	{
		command = data->argv[0];
		actual_command = _which(data);
		if (actual_command == NULL && isatty(STDIN_FILENO))
		{
			data->status = 127;
			printf("%s: %s: not found\n", data->file_name, data->argv[0]);
		}
		else
		{
			child_pid = fork();
			if (child_pid == -1)
			{
				perror("Error");
				return;
			}
			else
			{
				if (child_pid == 0)
				{

					execution_status = execve(actual_command, data->argv, environ);
					if (execution_status == -1 && isatty(STDIN_FILENO))
					{
						perror("Error");
						free_data(data, 1);
						if (errno == EACCES)
							exit(126);
						exit(1);
					};
				}
				else
				{
					wait(&(data->status));
					if (WIFEXITED(data->status))
					{
						data->status = WEXITSTATUS(data->status);
						if (data->status == 126)
							print_error(data, "Permission denied\n");
					}
				}
			}
		}
	}

}
