#include "monty.h"
/**
 * swap - Swaps the top two elements of the stack
 *
 * Description:
 * This function swaps the positions of the top two elements in the stack. If
 * the stack contains fewer than two elements, it prints an error message.
 *
 * Global Variables:
 * - v.h: Points to the head of the stack.
 *
 * Error Handling:
 * If the stack contains fewer than two elements, it calls the error function
 * with error code 8 to print an error message and exit the program.
 */
void swap(void)
{
	if (v.h && v.h->next)
	{
		v.h->prev = v.h->next;
		if (v.h->next->next)
		{
			v.h->next = v.h->next->next;
			v.h->next->prev = v.h;
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
