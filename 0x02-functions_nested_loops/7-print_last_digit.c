#include "main.h"

/**
 * print_last_digit - puint last digit of a number.
 *
 * @n: takes mumber input
 *
 * Return: lastDigit
*/

int print_last_digit(int n)
{
	int lastDigit;

	if (n > 0)
		lastDigit = -1 * (n % 10);
	else
		lastDigit = n % 10;

	_putchar(lastDigi + '0');
	return (lastDigit);

}
