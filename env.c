#include "main.h"

/**
 * env - prints the environment
 *
 * Return: Always 0.
 */
int env(void)
{
	unsigned int i;
	extern char **environ;

        i = 0;
	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}

	return(0);
}
