#include "main.h"

/**
 * main - reads a line, splits it and executes the command
 * @ac: Argument Count
 * @argv: Argument Vector
 * Return: zero on success and -1 on failure
 */

int main(int ac, char **argv)
{
	char __attribute__((unused)) *prompt = "$ ", *line = NULL, *line_copy = NULL;
	size_t size = 0;
	ssize_t chars_read;
	const char *del = " \n";
	int tokens = 0, i;
	char *token, *file_name = argv[0];
	(void)ac;
	

	while (1)
	{
		/* if (isatty(STDIN_FILENO)) */
		write(STDOUT_FILENO, "$ ", 2);
		chars_read = getline(&line, &size, stdin);

		if (chars_read == -1)
		{
			if (isatty(STDIN_FILENO))
			{
				write(STDOUT_FILENO, "\n", 1);
				/*free(line);*/
			}
			exit(0);
		}

		line_copy = malloc(sizeof(char) * chars_read);
		if (line_copy == NULL)
		{
			perror("tsh: memory allocation error");
			return (-1);
		}

		_strcpy(line_copy, line);

		token = strtok(line, del);

		while (token != NULL)
		{
			tokens++;
			token = strtok(NULL, del);
		}
		tokens++;

		argv = malloc(sizeof(char *) * tokens);

		token = strtok(line_copy, del);

		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			_strcpy(argv[i], token);
			token = strtok(NULL, del);
		}
		argv[i] = NULL;
		/* Check if the enterd command is a built-in*/
		if (strcmp(argv[0], "exit") == 0)
		{
			exit(0);
		}
		else
		{
			if (strcmp(argv[0], "env") == -1)
			{
				env();
			}
			else
			{
			/* execute the command */
			execute(argv, file_name);
			}
		}
	}


	/* free up allocated memory */
	free(line_copy);
	free(line);

	return (0);
}
