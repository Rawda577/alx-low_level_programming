#include "lists.h"
#include <stdlib.h>

/**
 * free_listint2 - Frees a listint_t list and sets the head to NULL
 * @head: Pointer to the pointer to the beginning of the list
 */
void free_listint2(listint_t **head)
{
	if (head == NULL || *head == NULL)
		return;

	while (*head != NULL)
	{
		listint_t *temp = *head;
		*head = (*head)->next;
		free(temp);
	}
	*head = NULL;
}
