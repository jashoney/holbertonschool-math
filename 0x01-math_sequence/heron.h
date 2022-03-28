#ifndef HERON_H
#define HERON_H

/**
 * struct node - a linked list node
 * @n: a floating point number
 * @next: a ptr to the next node;
 */

typedef struct node
{
	double n;
	struct node *next;
} t_cell;

t_cell *heron(double p, double x0);

#endif
