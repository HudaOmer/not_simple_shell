#include "main.h"

/**
 * tokenization - make the tokens (not used)
 * @data: all data needed
 * @argv: Argument Vector
 * Return: 0 on success -1 otherwise
 */
int tokenization(data_t *data, char **argv)
{
	char *token = NULL;
	const char *del = " \n";
	int i, tokens = 0;
	(void)argv;

	token = _strtok(data->line, del);
	while (token != NULL)
	{
		tokens++;
		token = _strtok(NULL, del);
	}
	tokens++;
	data->argv = malloc(sizeof(char *) * tokens);
	token = strtok(data->line, del);
	for (i = 0; token != NULL; i++)
	{
		data->argv[i] = malloc(sizeof(char) * _strlen(token));
		_strcpy(data->argv[i], token);
		token = strtok(NULL, del);
	}
	data->argv[i] = NULL;
	return (0);
}

/**
 * all_space - checks if the command has only spaces
 * @line: to check
 * Return: 1 if all space 0 oterwise
 */
int all_space(char *line)
{
	unsigned int i, length = _strlen(line) - 1;

	for (i = 0; i < length; i++)
	{
		if (line[i] != ' ')
			return (0);
	}
	return (1);
}

/**
 * my_shell - loop to get input
 * @data: all data needed
 * @argv: Argument Vector
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
			exit(data->status);
		}
		else if (all_space(data->line) == 1)
		{
			data->line_count++;
			continue;
		}
		line_copy = malloc(sizeof(char) * chars_read);
		if (line_copy == NULL)
		{
			if (isatty(STDIN_FILENO))
				perror("tsh: memory allocation error");
			exit(-1);
		}
		_strcpy(line_copy, data->line);
		data->argv = split(line_copy);
		is_builtin(data);
	}
	free(line_copy);
}
