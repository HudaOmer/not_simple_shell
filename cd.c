#include "main.h"

/**
 * _cd_shell - changes current directory
 * @data: data needed
 * Return: 1 on success
 */
int _cd_shell(data_t *data)
{
	char *dir;
	int ishome, ishome2, isddash;

	dir = data->argv[1];

	if (dir != NULL)
	{
		ishome = _strcmp("$HOME", dir);
		ishome2 = _strcmp("~", dir);
		isddash = _strcmp("--", dir);
	}

	if (dir == NULL || !ishome || !ishome2 || !isddash)
	{
		cd_to_home(data);
		return (1);
	}

	if (_strcmp("-", dir) == 0)
	{
		cd_previous(data);
		return (1);
	}

	if (_strcmp(".", dir) == 0 || _strcmp("..", dir) == 0)
	{
		cd_dot(data);
		return (1);
	}

	cd_to(data);
	return (1);
}

