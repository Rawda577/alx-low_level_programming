#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * strtow - Splits a string into words.
 * @str: The string to split.
 *
 * Return: A pointer to an array of strings (words)
 * , or NULL if an error occurs.
 */
char **strtow(char *str)
{
	char **result;
	int count = 0, i = 0;
	char *tmp = str;

	if (!str || !*str)
		return (NULL);

	while (*tmp && *tmp == ' ')
		tmp++;

	while (*tmp)
	{
		if (*tmp++ == ' ')
			count++;
	}

	result = malloc((count + 2) * sizeof(char *));
	if (!result)
		return (NULL);

	tmp = strtok(str, " ");
	while (tmp)
	{
		result[i++] = strdup(tmp);
		tmp = strtok(NULL, " ");
	}

	result[i] = NULL;

	return (result);
}
