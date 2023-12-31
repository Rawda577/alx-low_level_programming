#include "main.h"

/**
 * print_times_table - prints time table if n
 *
 * @n: tales number input
*/

void print_times_table(int n)
{
	int prod, mult, num;

	if (n <= 15 && n >= 0)
	{
		for (num = 0; num <= n; num++)
		{
			_putchar(48);
			for (mult = 1; mult <= n; mult++)
			{
				_putchar('0');
				_putchar(',');
				_putchar(' ');

				prod = num * mult;

				if (prod <= 9)
				{
					_putchar(' ');
					_putchar(' ');
				}
				else if (prod <= 99)
				{
					_putchar(' ');
				}

				_putchar((prod / 100) + '0');
				_putchar(((prod / 10) % 10) + '0');
				_putchar((prod % 10) + '0');


				if (mult < n)
				{
					_putchar(',');
					_putchar(' ');
				}
			}
			_putchar('\n');
		}
	}
}
