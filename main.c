#include "main.h"

/**
 * main - main function
 *
 * Return: 0 success
 */

int main(void)
{
	char *prompt = "$ ";
	char *line = NULL, *line_copy = NULL;
	size_t size = 0;
	ssize_t chars_read;
	const char *del = " \n";
	int tokens = 0;
	char *token;
	int i;
	(void)ac;

	while (1) 
	{
		printf("%s", prompt);
		chars_read = getline(&line, &size, stdin);

		if (chars_read == -1)
		{
			printf("\n");
			 return (-1);
		}

		line_copy = malloc(sizeof(char) * chars_read);
		if (line_copy == NULL)
		{
			perror("tsh: memory allocation error");
			return (-1);
		}

		strcpy(line_copy, line);

		token = strtok(line, del);

		while (token != NULL)
		{
			tokens++;
			token = strtok(NULL, del);
		}
		tokens++;

		argv = malloc(sizeof(char *) * tokens);

		token = strtok(line_copy, del);

		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[i], token);
			token = strtok(NULL, del);
		}
		argv[i] = NULL;
		/* execute the command */
		execute(argv);
	} 


	/* free up allocated memory */ 
	free(line_copy);
	free(line);

	return (0);
}
