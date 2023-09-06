#include "main.h"

/**
 * _stlen - find lenght of a string
 * @s: string
 * Reutrn: int
*/

int _stlen(char *s)
{
	int size = 0;

	for (; s[size] != '\0'; size++)
		;
	return (size);
}

/**
 * *argstostr - description
 * @ac: int
 * @av: arguments
 * Return: string
*/

char *argstostr(int ac, char **av)
{
	int i = 0, nc = 0, j = 0, cmpt = 0;
	char *s;

	if (ac == 0 || av == 0)
		return (0);
	for (; i < ac; i++, nc++)
		nc += _stlen(av[i]);

	s = malloc(sizeof(char) * nc + 1);
	if (s == 0)
		return (0);
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++, cmpt++)
			s[cmpt] = av[i][j];

		s[cmpt] = '\n';
		cmpt++;
	}
	s[cmpt] = '\0';
	return (s);
}











