#include "main.h"

/**
 * _strlen - return length of a string
 * @s: points to array of chars
 * Description: does the job
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
 * _strcmp - comparison
 * @s1: pointer to the first string
 * @s2: pointer to the second string
 * Description: compare the stings
 *
 * Return: 0 is equal - if s1 is less if s1 is more
 */
int _strcmp(char *s1, char *s2)
{
	int count1 = 0, areequal = 0;

	while (s1[count1] != '\0' && s2[count1] != '\0')
	{
		if (s1[count1] != s2[count1])
		{
			areequal = s1[count1] - s2[count1];
			break;
		}
		count1++;
	}
	return (areequal);
}

/**
 * _startwith - check if the string starts with the sub
 * @string: to search
 * @substring: to search for
 * Return: NULL or the address of the next char of the string after sub
 */
char *_startwith(const char *string, const char *substring)
{
	while (*substring)
	{
		if (*substring++ != *string++)
			return (NULL);
		return (string);
	}
}

/**
 * _strcat - concatinate
 * @dest: pointer to destinaion array
 * @src: pointer to sourcce array
 * Description: append src into dest
 *
 * Return: pointer to the source
 */

char *_strcat(char *dest, char *src)
{
	int i = 0, count = 0;

	while (dest[count] != '\0')
	{
		count++;
	}
	while (src[i] != '\0')
	{
		*(dest + count) = src[i];
		i++;
		count++;
	}
	*(dest + count) = '\0';
	return (dest);
}

/**
 * printarray - prints an array of chars
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
