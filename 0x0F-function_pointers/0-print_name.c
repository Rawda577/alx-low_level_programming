#include "function_pointers.h"
#include <stdio.h>

/**
 * print_name - Prints a name using a function pointer.
 *
 * @name: The name to be printed.
 * @f: A pointer to the printing function to use.
 *
 * Return: void
 */
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;

		f(name);

}

