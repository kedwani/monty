#include "monty.h"
/**
 * fre - Frees memory allocated for the stack
 *
 * Return: void
 */
void fre(void)
{
	stack_t *tmp;

	tmp = v.h;
	while (v.h)
	{
		tmp = v.h->next;
		free(v.h);
		v.h = tmp;
	}
}
