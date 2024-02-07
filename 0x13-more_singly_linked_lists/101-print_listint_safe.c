#include <stdlib.h>
#include "lists.h"

/**
 * free_listint_safe - frees a listint_t list
 * @h: pointer to the head of the list
 *
 * Return: the size of the list that was free’d
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *temp;
	size_t count;

	if (h == NULL || *h == NULL)
	return (0);

	count = 0;
	while (*h)
	{
		temp = *h;
		*h = (*h)->next;
		free(temp);
		count++;
	}
	*h = NULL;
	return (count);
}
