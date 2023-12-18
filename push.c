#include "monty.h"
/**
 * push - Implements thy instruction, pushing a new element onto the stack
 *
 * Return: void
 */
void push(void)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (!new)
		error(5);
	new->n = v.d;
	new->prev = NULL;
	new->next = NULL;

	if (!v.h)
		v.h = new;
	else
	{
		new->next = v.h;
		v.h->prev = new;
		v.h = new;
	}
}
