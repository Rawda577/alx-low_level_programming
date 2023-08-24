#include "main.h"

/**
 * puts_half - print the second half of a string
 *
 * @str: the input string
 * Description: If odd number of chars, (lengh - 1) / 2
*/

void puts_half(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		/*empty loop body*/
	}

	i++;
	for (i /= 2; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
}
