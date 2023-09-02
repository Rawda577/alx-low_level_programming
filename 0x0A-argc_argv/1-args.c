#include <stdio.h>

/**
 * main - Print the number of command-line arguments passed.
 * @argc: Number of command-line arguments.
 * @argv: Pointer to an array of command-line arguments.
 * Return: 0 for success, non-zero for failure.
*/
int main(int argc, char *argv[] __attribute__((unused)))
{
	printf("%d\n", argc - 1);
	return (0);
}
