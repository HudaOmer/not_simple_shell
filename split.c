#include "main.h"

/**
 * _extralloc - add more space
 * @array: to add extra space at
 * @old: size
 * @new: size
 * Return: new extra array pointer
 */
char **_extralloc(char **array, size_t old, size_t new)
{
	char **newarray;
	size_t i;

	if (!array)
		return (malloc(sizeof(char *) * new));

	if (new == old)
		return (array);

	newarray = malloc(sizeof(char *) * new);
	if (!newarray)
		return (NULL);

	for (i = 0; array[i]; i++)
		newarray[i] = array[i];

	free(array);

	return (newarray);
}

/**
 * split - splits strings
 * @string: the string to split
 * Return: an array of each word of the string
 */
char **split(char *string)
{
	size_t i = 0, bufsize = 128;
	char **array;
	char *pointer, *del = " \n";

	array = malloc(sizeof(char *) * bufsize);
	if (!array)
	{
		printf(": allocation error\n");
		exit(EXIT_FAILURE);
	}

	pointer = strtok(string, del);
	array[i++] = pointer;

	while (pointer)
	{
		if (i == bufsize)
		{
			i += bufsize;
			array = _extralloc(array, i, sizeof(char *) * bufsize);
			if (!array)
			{
				printf(": allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
		pointer = strtok(NULL, del);
		array[i] = pointer;
		i++;
	}

	return (array);
}
