#include "main.h"

/**
 * split - splits strings
 * @string: the string to split
 * Return: an array of each word of the string
 */
char **split(char *string)
{
	size_t i = 0, bufsize = 128;
	char **array;
	char *pointer, *del = " ";

	array = malloc(sizeof(char *) * bufsize);
	if (!array)
	{
		printf("allocation failure");
		exit(EXIT_FAILURE);
	}

	pointer = strtok(string, del);
	array[i++] = pointer;

	while(pointer)
	{
		pointer = strtok(NULL, del);
		array[i] = pointer;
		i++;
	}

	return (array);
}
