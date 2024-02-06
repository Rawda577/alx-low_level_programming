#include "lists.h" /* Assuming this header file contains the definition of listint_t */
#include <stdio.h>
#include <stdlib.h>

/**
 * print_listint_safe - Prints a singly linked list of integers safely
 * @head: Pointer to the head of the list
 *
 * Return: The number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *current = head;
	size_t count =  0;

	if (head == NULL)
	{
		fprintf(stderr, "Error: List is empty.\n");
		exit(98);
	}

	while (current != NULL)
	{
		printf("[%p] %d\n", (void *)current, current->n);
		current = current->next;
		count++;
	}

	return (count);
}

