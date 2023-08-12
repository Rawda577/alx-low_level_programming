#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Print numbers of base16 in lowercase
 *
 * Return: Always 0 (success)
*/

int main(void)
{
	int digit = 48; /*48; decimal rep of 0*/

	while (digit <= 102) /*102; demical rep of f*/
	{
		putchar(digit);

		/* after 9 we jump till 96; `*/
		if (digit == 57)
			digit += 39;
		digit++;
	}
	putchar('\n');

	return (0);
}
