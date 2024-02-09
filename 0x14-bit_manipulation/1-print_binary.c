#include "main.h"
#include <stdio.h>

/**
 * print_binary_recursive - Helper function
 * to recursively print binary representation
 * @n: The input number
 */
void print_binary_recursive(unsigned long int n)
{
	if (n > 1)
		print_binary_recursive(n >> 1);
	putchar((n & 1) + '0');
}

/**
 * print_binary - Prints the binary representation of a number
 * @n: The input number
 */
void print_binary(unsigned long int n)
{
	if (n == 0)
		putchar('0');
	else
		print_binary_recursive(n);
}
