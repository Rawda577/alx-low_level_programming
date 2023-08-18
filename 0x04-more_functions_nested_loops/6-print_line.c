#include "main.h"

/**
 * print_line - print a straight line
 *
 * Return: 0 (success)
 *
 * @n: number of underscores to print
 *
*/

void print_line(int n)
{
	int j;

	if (n <= 0)
		_putchar('\n');
	else
	{
		for (j = 1; j <= n; j++)
			_putchar('_');
			_putchar('\n');
	}
}
