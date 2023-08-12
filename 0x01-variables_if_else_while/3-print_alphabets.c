#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Print alphabet in lowercase then in uppercase
 *
 * Return: Always 0 (success)
*/

int main(void)
{
	char ch = 'a';
	char CH = 'A';

	/*prints a - z*/
	while (ch <= 'z')
	{
		putchar(ch);
		ch++;
	}

	/*prints A -Z*/
	while (CH <= 'z')
	{
		putchar(CH);
		CH++;
	}
	putchar('\n');

	return (0);
}
