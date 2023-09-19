#include "main.h"

/**
 * main - reads a line, splits it and executes the command
 * @argc: Argument Count
 * @argv: Argument Vector
 * Return: zero on success and -1 on failure
 */
int main(int argc, char **argv)
{
	char *token, *line_copy = NULL;
	size_t size = 0;
	ssize_t chars_read;
	const char *del = " \n";
	int i, tokens = 0;
	data_t data[] = { DATA_INIT };
	int fd = 2;

	/* read command from file situation*/
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			cant_open(argc, argv);
			return (EXIT_FAILURE);
		}
		data->readfd = fd;
	}
	pop_env(data);
	read_history(data);
	shell(data, argv);
	return (EXIT_SUCCESS);
}
	/* set_data(data, argv); */

	data->file_name = argv[0];
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		chars_read = getline(&(data->line), &size, stdin);
		if (chars_read == -1)
		{
			if (isatty(STDIN_FILENO))
			{
				write(STDOUT_FILENO, "\n", 1), free(data->line);
			}
			exit(0);
		}
		line_copy = malloc(sizeof(char) * chars_read);
		if (line_copy == NULL)
		{
			if (isatty(STDIN_FILENO))
				perror("tsh: memory allocation error");
			return (-1);
		}
		_strcpy(line_copy, data->line), token = strtok(data->line, del);
		while (token != NULL)
		{
			tokens++, token = strtok(NULL, del);
		}
		tokens++;
		data->argv = malloc(sizeof(char *) * tokens);
		token = strtok(line_copy, del);
		for (i = 0; token != NULL; i++)
		{
			data->argv[i] = malloc(sizeof(char) * strlen(token));
			_strcpy(data->argv[i], token);
			token = strtok(NULL, del);
		}
		data->argv[i] = NULL;/* Check if the enterd command is a built-in*/
		is_builtin(data);
	} /* free up allocated memory */
	free(line_copy), free(data->line);
	return (0);
}
