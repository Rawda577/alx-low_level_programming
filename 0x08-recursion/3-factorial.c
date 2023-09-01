#include "main.h"

/**
 * factorian - find factorian
 * @n: int
 * Return: int
*/

int factorian(int n)
{
	if (n < 0)
	{
		return (-1);
	}
	else if (n == 0)
	{
		return (n);
	}
	return (n * factorian(n - 1));
}

