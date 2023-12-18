#include "monty.h"
void pop(void)
{
	stack_t *tmp;
	
	if (v.h)
	{
		if (v.h->next == NULL)
		{
			tmp = v.h;
			free(tmp);
			v.h = NULL;
		}
	else
		{
			v.h = v.h->next;
			free(v.h->prev);
			v.h->prev = NULL;
		}
	}
	else
		error(7);
}
