#include "main.h"

/**
 * _strlen - reurns the lrngth if a srtring
 *
 * @s: string paramater input
 *
 * Return: length of string
*/

int _strlen(char *s)
{
	int counter;
	
	for (counter = 0; *s != '\0'; s++)
		++counter;

	return (counter);
}
