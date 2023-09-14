#include "function_pointers.h"

/**
 * print_name - a function that Prints name
 * @name: The string name
 * @f: the printing function point
*/
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;

	f(name);
}
