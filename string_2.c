#include "main.h"

/*
 * _strcpy - function to copy strings
 * @dest: destination string
 * @source: source string
 * Return: a pointer to the destination string
 */
char *_strcpy(char *dest, const char *src)
{
	int i;

	if (dest == NULL)
	{
		return (NULL);
	}

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}

/**
 * _strdup - copies array content
 * @str: string to be copied
 * Return: NULL or the allocated array
 */
char *_strdup(const char *str)
{
	unsigned int i = 0, size = 0;
	char *s;

	if (str == NULL)
		return (NULL);
	while (*(str + i) != '\0')
	{
		size++;
		i++;
	}

	s = malloc(sizeof(char) * size + 1);
	if (s == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
	{
		*(s + i) = *(str + i);
	}
	*(s + i) = '\0';
	return (s);

}

/**
 * _puts - prints a string
 * @str: string to be printed
 * Return: Nothing
 */
void _puts(char *str)
{
	int i;

	if (str == NULL)
		return;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	int x;

	x = write(1, &c, 1);
	return (x);
}
