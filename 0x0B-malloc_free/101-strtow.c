#include <stdlib.h>

/**
 * _strlen - Returns the length of a string.
 * @str: The string to calculate the length of.
 *
 * Return: The length of the string.
 */
int _strlen(char *str)
{
	int len = 0;

	while (str[len])
		len++;

	return (len);
}

/**
 * count_words - Count the number of words in a string.
 * @str: The input string.
 *
 * Return: The number of words.
 */
int count_words(char *str)
{
	int word_count = 0, i, len = _strlen(str);

	for (i = 0; i < len; i++)
	{
	if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
		word_count++;
	}

	return (word_count);
}

/**
 * copy_word - Copy a word from a string.
 * @src: The source string.
 * @dest: The destination string.
 * @start: The start position of the word.
 * @end: The end position of the word.
 */
void copy_word(char *src, char *dest, int start, int end)
{
	int i, j = 0;

	for (i = start; i < end; i++)
	{
		dest[j] = src[i];
		j++;
	}
	dest[j] = '\0';
}

/**
 * strtow - Splits a string into words.
 * @str: The input string.
 *
 * Return: An array of strings (words) or NULL if str is NULL or empty.
 */
char **strtow(char *str)
{
	if (str == NULL || *str == '\0')
	return (NULL);

	int i, j, k, word_count = count_words(str), len = _strlen(str);
	char **words;

	if (word_count == 0)
	return (NULL);

	words = malloc((word_count + 1) * sizeof(char *));
	if (words == NULL)
	return (NULL);

	for (i = 0, j = 0; i < len; i++)
	{
	if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
	{
		int word_len = 0;

		for (k = i; k < len && str[k] != ' '; k++, word_len++)
		;

		words[j] = malloc((word_len + 1) * sizeof(char));
		if (words[j] == NULL)
	{
		while (j > 0)
			free(words[--j]);
		free(words);
		return (NULL);
	}

		copy_word(str, words[j], i, i + word_len);
		j++;
		i += word_len;
	}
	}

	words[word_count] = NULL;
	return (words);
}

