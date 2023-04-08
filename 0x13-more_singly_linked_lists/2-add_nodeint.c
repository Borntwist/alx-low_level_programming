#include "lists.h"

/**
 * add_nodeint - adds a new node at the beginning of a listint_t list
 * @head: double pointer to the start of list
 * @n: k data
 *
 * Return: the address of the new element, else, NULL
 */

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *k;

	k = malloc(sizeof(listint_t));
	if (k == NULL)
		return (NULL);

	k->n = n;
	/*add new node at the beginning of the list*/
	k->next = *head;
	/*go to the next node*/
	*head = k;

	return (k);
}
