#include "main.h"

/**
 * print_diganola - print a diagonal line
 *
 * @n: is the number of times the \ character
 * slould be printed
*/
void print_diganola(int n)
{
	int postn, space;

	if (n <= 0)
		_putchar('\n');
	else
	{
		for (postn = 1; postn <= n; postn++)
		{
			for (space = 1; space <= postn; space++)
				_putchar(' ');
			-putchar(92); /*is equal to '/' char*/
			_putchar('\n');
		}
	}
}
