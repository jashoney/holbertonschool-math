#include <stdio.h>
#include <stdlib.h>
#include "heron.h"

/**
 * heron - puts a heron series in a linked list
 * @b: the number to be used
 * @x0: the first guess in the sequence
 * Return: a ptr to the start of the linked list
 */

t_cell *heron(double b, double x0)
{
	double test = 1;
	t_cell *head, *current, *newnode;

	current = malloc(sizeof(*current));
	if (current == NULL)
		return (NULL);
	head = current;
	current->n = x0;
	current->next = NULL;
	while (test > 0.0000001)
	{
		newnode = malloc(sizeof(*newnode));
		if (newnode == NULL)
			return (NULL);
		newnode->n = 0.5 * (current->n + b / current->n);
		newnode->next = current;
		test = newnode->n - current->n;
		if (test < 0)
			test = test * -1;
		if (test < 0.0000001)
			break;
		current = newnode;
		head = current;
	}
	return (head);
}
