#include "main.h"

/**
 * main - main function
 *
 * Return: 0 success
 */

int main()
{
	int i = 0;
	char string[] = "Hello world today is a new day";
	char **array;

	array = split(string);

	while(array[i])
	{
		printf("%s.", array[i++]);
	}

	return 0;
}
