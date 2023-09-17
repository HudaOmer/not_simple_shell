#include "main.h"

/**
 * _memset - a function
 * @s: pointer to array
 * @b: character to insert
 * @n: first n bytes of the memory area pointed to by s
 * Return: pointer to s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * _freess - frees a string of strings
 * @pp: string of strings
 */
void _freess(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/** _freenull - free pointer and null address
 * @p: pointer
 * Return: 1 if freed, 0 otherwise
 */
int _freenull(void **p)
{
	if (p && *p)
	{
		free(*p);
		*p = NULL;
		return (1);
	}
	return (0);
}

/**
 * _realloc - reallocate with different size
 * @ptr: pointer to previosly allocated array
 * @old_size: the old size in bytes
 * @new_size: the new size in bytes
 * Return: pointer to different array or NULL
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *s;
	unsigned int i, x = old_size;

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (old_size == new_size)
		return (ptr);
	s = malloc(new_size);
	if (s == NULL)
		return (NULL);
	if (ptr == NULL)
		return (s);
	if (old_size > new_size)
	{
		x = new_size;
	}
	for (i = 0; i < x; i++)
	{
		s[i] = *((char *)ptr + i);
	}

	free(ptr);
	return (s);

}
