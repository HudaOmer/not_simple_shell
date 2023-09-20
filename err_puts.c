#include "main.h"

/**
 *_eputs - prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		putc_to_stderr(str[i]);
		i++;
	}
}

/**
 * putc_to_stderr - writes the character c to stderr
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int putc_to_stderr(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * putc_to_fd - writes the character c to given fd
 * @c: The character to print
 * @fd: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int putc_to_fd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * puts_to_fd - prints an input string
 * @str: the string to be printed
 * @fd: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int puts_to_fd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += putc_to_fd(*str++, fd);
	}
	return (i);
}


/**
 * cant_open - handles error on open function
 * @ac: Argumwnt Count
 * @argv: Argument Vector
 * Return: Nothing
 */
void cant_open(int __attribute__((unused)) ac, char **argv)
{
	if (errno == EACCES)
		exit(126);
	if (errno == ENOENT)
	{
		_eputs(argv[0]);
		_eputs(": 0: Can't open ");
		_eputs(argv[1]);
		putc_to_stderr('\n');
		putc_to_stderr(BUF_FLUSH);
		exit(127);
	}
}
