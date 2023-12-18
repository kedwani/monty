#include "monty.h"
void pop(void)
{
	if (v.h)
	{
		v.h = v.h->next;
		free(v.h->prev);
		v.h->prev = NULL;
	}
	else
		error(7);
}
