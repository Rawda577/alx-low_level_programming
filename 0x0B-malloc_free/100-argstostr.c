#include <stdlib.h>

/**
 * argstostr - Concatenates all the arguments of your program.
 * @ac: The argument count.
 * @av: An array of strings containing the arguments.
 *
 * Return: A pointer to the concatenated string, or NULL if it fails.
 */
char *argstostr(int ac, char **av)
{
	int i, j, len = 0, total_len = 0;
	char *str;

	if (ac == 0 || av == NULL)
	return (NULL);

	/* Calculate the total length of the concatenated string */
	for (i = 0; i < ac; i++)
	{
	for (j = 0; av[i][j] != '\0'; j++)
		len++;
	total_len += len + 1; /* Add 1 for newline character */
	len = 0;
	}

	/* Allocate memory for the concatenated string */
	str = malloc(sizeof(char) * total_len + 1); /* Add 1 for null terminator */

	if (str == NULL)
	return (NULL);

	/* Copy the arguments to the concatenated string with newlines */
	for (i = 0, total_len = 0; i < ac; i++)
	{
	for (j = 0; av[i][j] != '\0'; j++)
		str[total_len++] = av[i][j];
	str[total_len++] = '\n'; /* Add newline character */
	}

	str[total_len] = '\0'; /* Null-terminate the string */
	return (str);
}
