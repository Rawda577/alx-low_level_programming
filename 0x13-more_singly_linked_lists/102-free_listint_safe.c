#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t linked list safely
 * @h: Pointer to a pointer to the head of the linked list
 *
 * Return: The size of the list that was freed
 */
size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	listint_t *current, *next;

	if (h == NULL || *h == NULL)
		return (0);

	current = *h;
	while (current)
	{
		count++;
		next = current->next;

		/* Check if the current node has already been visited */
		if (((void *)current - (void *)current->next) >= 0)
		{
			free(current);
			*h = NULL;
			break;
		}

		free(current);
		current = next;
	}

	*h = NULL;
	return (count);
}

