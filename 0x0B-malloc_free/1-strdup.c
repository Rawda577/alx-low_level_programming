#include "main.h"

/**
 * _strdup - Duplicates a string in memory.
 * @str: The string to duplicate.
 *
 * Return: 0
 */
char *_strdup(char *str)
{
	int i = 0, size = 0;
	char *m;

	if (str == NULL)
		return (NULL);
	for (; str[size] != '\0'; size++)
	;

	/* +1 on the soze puts the end if string character */
	m = malloc((size + 1) * sizeof(*str));
	if (m == NULL)
		return (NULL);

		for (; i < size; i++)
			m[i] = str[i];
		m[i] = '\0';

	return (m);
}
