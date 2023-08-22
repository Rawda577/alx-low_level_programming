#include "main.h"

/**
 * swap_int - swap the values of two integers
 * using two input paramaters
 *
 * @a: input paramater 1
 * @b: inprt paramater 2
 *
 * Return: Nothing
*/

void swap_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
