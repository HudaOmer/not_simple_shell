#include "main.h"

/**
 * free_data_t - frees data structure
 *
 * @data: data needed
 * Return: void
 */
void free_data_t(data_t *data)
{
	unsigned int i;

	for (i = 0; data->environ[i]; i++)
	{
		if (data->environ && data->environ[i])
			free(data->environ[i]);
	}
	for (i = 0; data->argv && data->argv[i]; i++)
		free(data->argv[i]);

	if (data->argv)
		free(data->argv);
	if (data->file_name)
		free(data->file_name);
	if (data->environ)
		free(data->environ);
	if (data->line)
		free(data->line);
	/*free(data->pid);*/
}

/**
 * set_data_t - Initialize data structure
 *
 * @data: data needed
 * @argv: Argument Vector
 * Return: void
 */
void set_data_t(data_t *data, char **argv)
{
	unsigned int i;

	data->argv = argv;
	data->line = NULL;
	/*datash->args = NULL;*/
	/*datash->status = 0;*/
	data->line_count = 0;

	for (i = 0; environ[i]; i++)
		;

	data->environ = malloc(sizeof(char *) * (i + 1));

	for (i = 0; environ[i]; i++)
	{
		data->environ[i] = _strdup(environ[i]);
	}

	data->environ[i] = NULL;
	/*data->pid = aux_itoa(getpid()); */
}

/**
 * main - reads a line, splits it and executes the command
 * @argc: Argument Count
 * @argv: Argument Vector
 * Return: zero on success and -1 on failure
 */
int main(int argc, char **argv)
{
	int fd = 2;
	data_t data[] = { DATA_INIT };
	int ret_val = 0;

	data->file_name = argv[0];
	set_data_t(data, argv);
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
	signal(SIGINT, get_sigint);
	my_shell(data, argv);

	ret_val = data->status;

	free_list(&(data->env));
	free_data_t(data);
	return (ret_val);
}
