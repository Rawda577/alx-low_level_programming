#include <stdlib.h>
#include "lists.h"

/**
 * free_listint2 - Frees a listint_t list and sets the head to NULL.
 * @head: Pointer to the head of the list.
 */
void free_listint2(listint_t **head)
{
	if (head == NULL || *head == NULL)
		return;

	listint_t *current, *next;

	current = *head;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
		*head = NULL;
}
