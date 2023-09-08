#include "main.h"
#include <stdlib.h>

/**
 * _memset - fills memory with a constant byte.
 * @s: pointer to the memory to be filled.
 * @b: the constant byte to fill the memory with.
 * @n: the number of bytes to be filled.
 *
 * Return: a pointer to the memory area 's'.
*/

void *_memset(char *s, char b, unsigned int n)
{
	char *ptr = s;

	while (n--)
		*s++ =  b;
	return (ptr);
}

/**
 * _calloc - allacates memory for an array, using malloc
 * @nmemb: array length
 * @size: size of each element
 * Return: pointer
*/

void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *m;

	if (size == 0 || nmemb == 0)
		return (NULL);
	m = malloc(size * nmemb);
	if (m == NULL)
		return (NULL);
	_memset(m, 0, size * nmemb);
	return (m);
}
