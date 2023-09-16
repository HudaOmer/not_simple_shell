#include "main.h"

/**
 * env - prints the environment
 *
 * Return: Always 0.
 */
int env(void)
{
	unsigned int i;

	i = 0;
	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}

	return (0);
}

/** 
 * _setenv - sets a new environment variable or updates environ
 * @name: name of variable
 * @value: value of variable
 * @overwrite: 0 or 1
 * Return:  zero
 */
int set_env(char *name, char *value, int overwrite)
{
	int i = 0, len = 0;
	char *new;

	if(!name || !value)
		return (-1);
	while (environ[i])
	{
		len = strlen(name);
		if(strncmp(environ[i], name, len) == 0)
		{
			if(overwrite)
			{
				new = malloc(_strlen(name + _strlen(value) + 2));
				_strcpy(new, name);
				_strcat(new, "=");
				_strcat(new, value);
				environ[i] = new;
				return (0);
			}
			return (0);
		}
		i++;
	}
	new = malloc(_strlen(name + _strlen(value) + 2));
	_strcpy(new, name);
	_strcat(new, "=");
	_strcat(new, value);
	environ[i] = new;
	environ[i+1] = NULL;
	free(new);
	return (0);
}

/**
 * _setenv - Initialize a new environment variable,
 *  or modify an existing
 *  Return: Always 0
 */
int _setenv(char **argv)
{
	if (argv[1] == NULL || argv[2] == NULL)
	{
		printf("Incorrect number of arguements \n");
		return (1);
	}
	if (set_env(argv[0], argv[1], atoi(argv[2])))
		return (0);
	return (1);
}
