#include "main.h"

/**
 * factorial - calculates the factorial of a number
 * @n: input number
 *
 * Return: factorial of the number if n >= 0, otherwise -1
 */
int factorial(int n)
{
	if (n < 0)
		return (-1);
	else if (n == 0 || n == 1)
		return (1);
	else
		return (n * factorial(n - 1));
}
