#include "main.h"

/**
 * cant_open - handles error on open function
 *
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
