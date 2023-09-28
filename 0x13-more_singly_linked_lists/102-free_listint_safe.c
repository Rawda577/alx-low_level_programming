#include "lists.h"
#include <stdlib.h>

/**
 * free_listint_safe - Frees a listint_t linked list.
 * @h: Pointer to the head of the list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *current, *temp;
	size_t nodes_count = 0;

	if (h == NULL || *h == NULL)
	return (0);

	current = *h;
	while (current != NULL)
	{
	nodes_count++;
	temp = current;
	current = current->next;

	if (temp < current)
	{
		free(temp);
	}
	else
		{
		*h = NULL;
		return (nodes_count);
		}
	}

	*h = NULL;
	return (nodes_count);
}
