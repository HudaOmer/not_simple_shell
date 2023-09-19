#include "main.h"

/**
 * tokenization - make the tokens
 * @data: all data needed
 * Return: 0 on success -1 otherwise
 */
int tokenization(data_t *data, char **argv)
{
	char *token = NULL;
	const char *del = " \n";
	int i, tokens = 0;
	(void)argv;

	token = strtok(data->line, del);
	while (token != NULL)
	{
		tokens++, token = strtok(NULL, del);
	}
	tokens++;
	data->argv = malloc(sizeof(char *) * tokens);
	token = strtok(data->line, del);
	for (i = 0; token != NULL; i++)
	{
		data->argv[i] = malloc(sizeof(char) * strlen(token));
		_strcpy(data->argv[i], token);
		token = strtok(NULL, del);
	}
	data->argv[i] = NULL;
	return (0);
}

/**
 * my_shell - loop to get input
 * @data: all data needed
 * Return: nothing
 */
void my_shell(data_t *data, char **argv)
{
	char *line_copy = NULL;
	size_t size = 0;
	ssize_t chars_read;

	data->file_name = argv[0];
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		chars_read = get_line(&(data->line), &size, stdin);
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
			exit (-1);
		}
		_strcpy(line_copy, data->line);
		tokenization(data, argv);
		is_builtin(data);
	}
	free(line_copy);
}
