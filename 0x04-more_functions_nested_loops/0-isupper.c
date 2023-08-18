#include "main.h"

/**
 * _isupper -check if c is upper
 *
 * @C: input for alphabet
 *
 * Return: 1 if its uppercase. 0 if not
*/

int _isupper(int C)
{
	if (C >= 65 && C <= 90)
		return (1);
	else
		return (0);
}
