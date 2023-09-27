#include <stdio.h>
#include <stddef.h>
#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t linked list safely
 * @head: Pointer to the head of the list
 *
 * Return: The number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *tortoise, *hare;
	size_t count = 0;

	tortoise = head;
	hare = head;

	while (tortoise && hare && hare->next)
	{
	printf("[%p] %d\n", (void *)tortoise, tortoise->n);
	count++;

	tortoise = tortoise->next;
	hare = hare->next->next;

		if (tortoise == hare)
		{
			printf("-> [%p] %d\n", (void *)tortoise, tortoise->n);
			printf("Loop starts at [%p]\n", (void *)tortoise);
			break;
		}
	}

	if (tortoise == hare)
	exit(98);

	return (count);
}
