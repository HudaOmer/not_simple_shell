#include "main.h"

/**
 * bring_line - change the poinetr of lineptr
 * @lineptr: where we want to place the buffer
 * @buffer: input from cmd
 * @n: size of line
 * @input: size of buffer
 */
void bring_line(char **lineptr, size_t *n, char *buffer, size_t input)
{

	if (*lineptr == NULL || *n < input) /* inisialise if empty or */
	{ /* the new input is larger */
		if  (input > BUFSIZE)
			*n = input;

		else
			*n = BUFSIZE;
		*lineptr = buffer;
	}
	else /* if the input is smaller store at the same line by cpy */
	{
		_strcpy(*lineptr, buffer);
		free(buffer);
	}
}
/**
 * get_line - read input from stream
 * @lineptr: buffer that stores the input from cmd
 * @n: size of lineptr
 * @stream: stream to read the input from
 * Return: the number of bytes written
 */
ssize_t get_line(char **lineptr, size_t *n, FILE *stream)
{
	int i;
	static ssize_t input;
	ssize_t return_value;
	char *buffer, t = 'z';

	if (input == 0)
		fflush(stream);
	else
		return (-1);
	input = 0;

	buffer = malloc(sizeof(char) * BUFSIZE);
	if (buffer == 0)
		return (-1);

	for (; t != '\n'; input++)
	{
		i = read(STDIN_FILENO, &t, 1);
		if (i == -1 || (i == 0 && input == 0))
		{
			free(buffer);
			return (-1);
		}
		if (i == 0 && input != 0)
		{
			input++;
			break;
		}
		if (input >= BUFSIZE)
			buffer = _realloc(buffer, input, input + 1);
		buffer[input] = t;
	}

	buffer[input] = '\0';
	bring_line(lineptr, n, buffer, input);
	(return_value) = input;
	if (i != 0)
		input = 0;
	return (return_value);
}
