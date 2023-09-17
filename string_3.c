#include "main.h"

/**
 * _strncpy - copy a part only
 * @dest: a pointer to destination array
 * @src: a pointer to source array
 * @n: an input integer indicating how much to copy
 * Description: copy n characters of source into dest
 *
 * Return: pointer to destenation
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	while (n)
	{
		if (src[i] == '\0')
			break;
		*(dest + i) = src[i];
		i++;
		n--;
	}
	while (n)
	{
		*(dest + i) = '\0';
		i++;
		n--;
	}
	return (dest);
}

/**
 * _strncat - concatenates two strings
 * @dest: the first string
 * @src: the second string
 * @n: the amount of bytes to be maximally used
 * Return: the concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int i = 0, count = 0;

	while (dest[count] != '\0')
	{
		count++;
	}
	while (src[i] != '\0' && n)
	{
		*(dest + count) = src[i];
		i++;
		count++;
		n--;
	}
	*(dest + count) = '\0';
	return (dest);
}

/**
 * _strchr - search for a chatacter
 * @s: poiter to string
 * @c: character to be found
 * Return: pointer to where c is found
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
