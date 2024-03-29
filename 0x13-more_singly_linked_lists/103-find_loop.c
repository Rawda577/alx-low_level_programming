#include "lists.h"

/**
 * find_listint_loop - Finds the start of a loop in a linked list
 * @head: Pointer to the head of the linked list
 *
 * Return: Address of the node where the loop starts, or NULL if no loop exists
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow = head, *fast = head;

	while (slow && fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			slow = head;
			while (slow && fast)
			{
				if (slow == fast)
					return (slow);
				slow = slow->next;
				fast = fast->next;
			}
		}
	}
	return (NULL);
}

