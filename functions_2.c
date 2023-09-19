#include "main.h"

/**
 * _erratoi - converts a string to an integer
 * @s: the string to be converted
 * Return: 0 if no numbers in string, converted number, -1 on error
 */
int _erratoi(char *s)
{
	int i = 0;
	unsigned long int result = 0;

	if (*s == '+')
		i++;
	for (;  s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			result *= 10;
			result += (s[i] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * print_error - a function prints an error message
 * @data: all data needed
 * @err_str: string containing error message
 * Return: 0 if no numbers exist, converted number or -1 (error)
 */
void print_error(data_t *data, char *err_str)
{
	_eputs(data->file_name);
	_eputs(": ");
	printd(data->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(data->argv[0]);
	_eputs(": ");
	_eputs(err_str);
}

/**
 * printd - function prints a decima number
 * @input: number to ptint
 * @fd: the filedescriptor
 * Return: number of characters printed
 */
int printd(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int i, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = putc_to_stderr;

	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;

	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
			__putchar('0' + current / i), count++;
		current %= i;
	}
	__putchar('0' + current), count++;

	return (count);
}

/**
 * convert_number - converter function, a clone of itoa
 * @num: number int
 * @base: base int type
 * @flags: argument flags
 * Return: string
 */
char *convert_number(long int num, int base, int flags)
{
	static char *array, buffer[50];
	char sign = 0, *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
		n = -num, sign = '-';

	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do {
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;

	return (ptr);
}
