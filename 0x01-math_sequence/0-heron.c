#include <stdlib.h>
#include "heron.h"

#define TEST 0.0000001

/**
 * heron - puts a heron series in a linked list
 * @b: the number to be used
 * @x0: the first guess in the sequence, starts as 1
 * Return: a ptr to the start of the linked list
 */

t_cell *heron(double b, double x0)
{
	double check = 1;
	t_cell *head = NULL, *current, *newnode;

	current = malloc(sizeof(*current));
	if (current == NULL)
		return (head);
	if (x0 < 1)
		return (head);
	head = current;
	current->n = x0;
	current->next = NULL;
	if (b == 1)
		return (head);
	if (b < 1)
		return (NULL);
	while (check >= TEST)
	{
		newnode = malloc(sizeof(*newnode));
		if (newnode == NULL)
			return (NULL);

		newnode->n = 0.5 * (current->n + b / current->n);
		newnode->next = current;

		if (current->n > 1)
			check = current->n - newnode->n;
		if (check < TEST)
			break;
		current = newnode;
		head = current;
	}
	return (head);
}
