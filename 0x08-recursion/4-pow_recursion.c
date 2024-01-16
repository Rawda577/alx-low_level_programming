#include "main.h"

/**
 * factorial - Calculates the factorial of a number
 * @n: The number to calculate the factorial of
 *
 * Return: The factorial of n
 */
int factorial(int n)
{
   /* If n is less than 0, return -1 to indicate an error */
	if (n < 0)
		return (-1);

	/* If n is 0, return 1 */
	else if (n == 0)
		return (1);
	/* Otherwise, return the product of n and the factorial of n - 1 */
	else
		return (n * factorial(n - 1));
}
