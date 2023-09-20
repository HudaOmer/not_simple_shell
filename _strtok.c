#include "main.h"

/**
 * cmp_chars - compare strings
 * @str: string
 * @delim: delimiter
 * Return: 1 equals, 0 if not equal
 */
int cmp_chars(char str[], const char *delim)
{
	unsigned int i, j, k;

	for (i = 0, k = 0; str[i]; i++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (str[i] == delim[j])
			{
				k++;
				break;
			}
		}
	}

	if (i == k)
		return (1);

	return (0);
}

/**
 * _strtok - tokenizattion
 * @str: string to be tokenized
 * @delim: delimiter
 * Return: part of the string
 */
char *_strtok(char str[], const char *delim)
{
	static char *splitted, *str_end;
	char *str_start;
	unsigned int i, istrue;

	if (str != NULL)
	{
		if (cmp_chars(str, delim))
			return (NULL);
		splitted = str;
		i = _strlen(str);
		str_end = &str[i];
	}
	str_start = splitted;
	if (str_start == str_end)
		return (NULL);

	for (istrue = 0; *splitted; splitted++)
	{
		if (splitted != str_start)
			if (*splitted && *(splitted - 1) == '\0')
				break;
		for (i = 0; delim[i]; i++)
		{
			if (*splitted == delim[i])
			{
				*splitted = '\0';
				if (splitted == str_start)
					str_start++;
				break;
			}
		}
		if (istrue == 0 && *splitted)
			istrue = 1;
	}
	if (istrue == 0)
		return (NULL);
	return (str_start);
}

