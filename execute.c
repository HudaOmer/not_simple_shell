#include "main.h"

/**
 * execute - function to fork, execute and wait
 *
 * Return : Nothing on success, -1 on faliure.
 */
void execute(char **argv)
{
	char *command = NULL, *actual_command = NULL;
	pid_t child_pid;
	int status;
	extern char **environ;	

	if(argv)
	{
		command = argv[0];
		actual_command = _which(command);
		if(actual_command == NULL)
		{
			printf("%s: not found\n", argv[0]);
		}
		else
		{
			child_pid = fork();
			if(child_pid == -1)
			{
				perror("Error");
			}
			else
			{
				if(child_pid == 0)
				{

					if (execve(actual_command, argv, environ) == -1)
					{
						printf("$0 :%s: not found\n", argv[0]);
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
