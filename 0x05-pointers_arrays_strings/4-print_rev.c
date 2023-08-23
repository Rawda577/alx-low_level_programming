#include "main.h"

/**
 * print_rov - prints roveesed string, followed by a new line
 * @s: pointer to the srting to print
 * Return: void
*/
void print_rev(char *s)
{
	int i = 0;

	while (s[i])
		i++;

	while (i--)
	{
		_putchar(s[i]);
	}
	_putchar('\n');
}
