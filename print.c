#include "main.h"

/**
 * print_number - prints an integer.
 * @n: input integer.
 * Return: no return.
 */

void print_number(int n)
{
	unsigned int i, ten = 1, count = 0, x;

	if (n < 0)
	{
		_putchar('-');
		n = n * -1;
	}
	if (n == 0)
		_putchar('0');
	x = n;
	while (x > 0)
	{
		x /= 10;
		count++;
	}
	for (i = 1; i < count; i++)
		ten *= 10;
	while (count)
	{
		_putchar((n / ten) % 10 + '0');
		count--;
		ten /= 10;
	}
}

/**
 * print_error - a function prints an error message
 * @data: all data needed
 * @err_str: string containing error message
 * Return: 0 if no numbers exist, converted number or -1 (error)
 */
void print_error(data_t *data, char *err_str)
{
	write(STDOUT_FILENO, data->file_name, _strlen(data->file_name));
	write(STDOUT_FILENO, ": ", 2);
	print_number(data->line_count);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, data->argv[0], _strlen(data->argv[0]));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, err_str, _strlen(err_str));
}

