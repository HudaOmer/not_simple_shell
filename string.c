#include "main.h"

/**
 * _strlen - return length of a string
 * @s: points to array of chars
 * Descripyion: does the job
 *
 * Return: the length
 */

int _strlen(char *s)
{
	int count = 0;

	while (*(s + count) != '\0')
		count++;
	return (count);

}

/**
 * printarrat - prints an array of chars
 * @array: to print
 * Return: void
 */
void printarray(char **array)
{
	size_t i = 0;

	printf("\"%s\"", array[i++]);
	while (array[i])
	{
		printf(", \"%s\"", array[i++]);
	}
	printf("\n");
}
