#include "monty.h"
/**
 * add - Adds the top two elements of the stack
 *
 * Description:
 * This function adds the values of the top two elements of the stack. If the
 * stack contains fewer than two elements, it prints an error message.
 *
 * Global Variables:
 * - v.h: Points to the head of the stack.
 *
 * Error Handling:
 * If the stack contains fewer than two elements, it calls the error function
 * with error code 9 to print an error message and exit the program.
 */
void add(void)
{
	if (v.h && v.h->next)
	{
		v.h->next->n += v.h->n;
		v.h = v.h->next;
		free(v.h->prev);
		v.h->prev = NULL;
	}
	else
		error(9);
}
