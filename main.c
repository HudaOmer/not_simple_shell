#include "main.h"

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

/**
 * main - main function
 *
 * Return: 0 success
 */

int main(void)
{
	size_t i = 1, buffersize;
	long int chs;
	char string[] = "Hello world today is a new day";
	char **array, *buffer, prompt[] = "#cisfun$ ";

	array = split(string);
	printarray(array);

	while (i)
	{
		printf("%s", prompt);
		chs = getline(&buffer, &buffersize, stdin);
		if (chs == -1)
		{
			printf("Error: getline()");
			return (-1);
		}
		buffer[_strlen(buffer) - 1] = '\0';
		array = split(buffer);
		printf("%s\n", buffer);
		printarray(array);
	}

	return (0);
}
