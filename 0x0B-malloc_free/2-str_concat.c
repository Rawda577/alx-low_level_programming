#include <stdlib.h>
#include <string.h>

/**
 * str_concat - concatenates two strings.
 * @s1: first string.
 * @s2: second string.
 *
 * Description: This function concatenates two strings.
 * If either string is NULL,
 * it treats it as an empty string. The function allocates memory for the new
 * string and returns a pointer to it.
 * If the memory allocation fails, the function
 * returns NULL.
 *
 * Return: pointer to the new string, or NULL if memory allocation fails.
*/

char *str_concat(char *s1, char *s2)
{
	char *result;
	size_t len1 = 0, len2 = 0;

	if (s1 != NULL)
		len1 = strlen(s1);
	if (s2 != NULL)
		len2 = strlen(s2);

	result = malloc((len1 + len2 + 1) * sizeof(char));
	if (result == NULL)
	return ((char *)NULL);

	if (s1 != NULL)
		strcpy(result, s1);
	if (s2 != NULL)
		strcat(result, s2);

	return (result);
}
