#include <stdio.h>
#include <stdlib.h>

/**
 * struct Node - Node of a singly linked list
 * @data: Integer data stored in the node
 * @next: Pointer to the next node
 */
typedef struct Node {
	int data;
	struct Node *next;
} Node;

/**
 * free_listint_safe - Frees a linked list safely
 * @h: Double pointer to the head of the list
 *
 * Return: Number of nodes freed
 */
int free_listint_safe(Node **h)
{
	Node *temp = NULL;
	int count =   0;

	if (*h == NULL)
		return (0);

	while (*h) {
		temp = *h;
		*h = (*h)->next;
		free(temp);
		count++;
	}

	*h = NULL;
	return (count);
}

/**
 * main - Entry point of the program
 *
 * Return:   0 on success
 */
int main(void)
{
	Node *head = NULL;
	Node *second = NULL;
	Node *third = NULL;

	head = (Node *)malloc(sizeof(Node));
	second = (Node *)malloc(sizeof(Node));
	third = (Node *)malloc(sizeof(Node));

	head->data =   1;
	head->next = second;

	second->data =   2;
	second->next = third;

	third->data =   3;
	third->next = NULL;

	printf("List before freeing:\n");
	for (Node *temp = head; temp != NULL; temp = temp->next)
		printf("%d ", temp->data);

	int count = free_listint_safe(&head);

	printf("\n%d nodes were freed.\n", count);

	return (0);
}

