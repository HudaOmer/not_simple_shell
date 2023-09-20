#include "main.h"

/**
 * start_with - check if the string starts with the sub
 * @string: to search
 * @substring: to search for
 * Return: NULL or the address of the next char of the string after sub
 */
char *start_with(const char *string, const char *substring)
{
	while (*substring)
	{
		if (*substring++ != *string++)
			return (NULL);
	}
	return ((char *)string);
}

/**
 * _getenv_var - gets an environment variable value
 * @name: of the variable
 * Return: the value of name variable
 */
char *_getenv_var(const char *name)
{
	int i = 0;
	char *variable = NULL;

	while (environ[i])
	{
		variable = start_with(environ[i], name);
		if (variable)
		{
			if (*variable == '=')
				return (++variable);
			variable = NULL;
		}
		i++;
	}
	return (NULL);
}
