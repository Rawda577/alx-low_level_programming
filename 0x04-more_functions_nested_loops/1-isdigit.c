#include "main.h"

/**
 * _isdigit - checks if input is digit between 0 - 9
 *
 * @C: input
 *
 * Return: 1 if is digit. 0 if not
 *
*/

int _isdigit(int C)
{
	if (C >= 48 && C <= 57)
		return (1);
	else
		return (0);
}
