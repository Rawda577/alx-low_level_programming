#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * print_listint_safe - Prints a listint_t linked list.
 * @head: Pointer to the head of the list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *slow, *fast;
	size_t count = 0;

	slow = head;
	fast = head;

	while (slow != NULL && fast != NULL && fast->next != NULL)
	{
	printf("[%p] %d\n", (void *)slow, slow->n);
	count++;

	slow = slow->next;
	fast = fast->next->next;

	if (slow == fast)
		{
		printf("-> [%p] %d\n", (void *)slow, slow->n);
		exit(98);
		}
	}

	return (count);
}
