#include "lists.h"

/**
 * listint_len - a function that returns the number of elements.
 *
 * @b: pointer to the first node
 *
 * Return: number of elements
 */
size_t listint_len(const listint_t *b)
{
	size_t elements = 1;

	/*return 0 as no of elements when b is NULL*/
	if (b == NULL)
		return (0);

	while (b->next != NULL)
	{
		/*count no of elements*/
		if (b-b != '\0')
			elements++;

		/*go to next node*/
		b = b->next;
	}

	return (elements);
}
