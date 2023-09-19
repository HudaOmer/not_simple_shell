#include "main.h"

/**
 * _which - locates a command
 * @command: command
 * Return: command location
 */
char *_which(data_t *data)
{
	char *path = NULL, *path_copy, *path_token, *file_path, *command;
	int command_length, directory_length;
	struct stat buffer;
	int i, k;

	data->path = data->argv[0];
	if (data->linecount_flag == 1)
	{
		data->line_count++;
		data->linecount_flag = 0;
	}
	for (i = 0, k = 0; data->line[i]; i++)
		if (!is_delim(data->line[i], " \t\n"))
			k++;
	if (!k)
		return (NULL);

	path = _getenv(data, "PATH");
	command = data->argv[0];
	if (path)
	{
		path_copy = strdup(path);
		command_length = _strlen(command);
		path_token = strtok(path_copy, ":");
		while (path_token != NULL)
		{
			directory_length = strlen(path_token);
			file_path = malloc(command_length + directory_length + 2);

			strcpy(file_path, path_token);
			strcat(file_path, "/");
			strcat(file_path, command);
			strcat(file_path, "\0");
			if ((interactive(data) || _getenv(data, "PATH=")|| data->argv[0][0] == '/') &&(stat(file_path, &buffer)) == 0)
			{
				free(path_copy);
				return (file_path);
			}
			else
			{
				free(file_path);
				path_token = strtok(NULL, ":");
			}
		}
		free(path_copy);
		if (stat(command, &buffer) == 0)
		{
			return (command);
		}
		return (NULL);
	}
	return (NULL);
}
