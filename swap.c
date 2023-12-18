#include "monty.h"
void swap(void)
{
	if (v.h && v.h->next)
	{
		v.h->prev = v.h->next;
		if (v.h->next->next)
		{
			v.h->next = v.h->next->next;
			v.h->next->next->prev = v.h;
		}
		else
			v.h->next = NULL;
		v.h->prev->next = v.h;
		v.h->prev->prev = NULL;
		v.h = v.h->prev;
	}
	else
		error(8);
}
