#include "monty.h"
/**
 * div - Divides the second element by the top element of the stack
 *
 * Description:
 * This function divides the value of the second element from the top of the
 * stack by the value at the top of the stack. If the stack contains fewer than
 * two elements, it prints an error message. If the top element is zero, it
 * prints an error message and exits the program.
 *
 * Global Variables:
 * - v.h: Points to the head of the stack.
 *
 * Error Handling:
 * If the stack contains fewer than two elements, it calls the error function
 * with error code 11 to print an error message and exit the program. If the
 * top element is zero, it calls the error function with error code 12.
 */
void dev(void)
{
	if (v.h && v.h->next)
	{
		if (v.h->n == 0)
			error(12);
		v.h->next->n /= v.h->n;
		v.h = v.h->next;
		free(v.h->prev);
		v.h->prev = NULL;
	}
	else
		error(11);
}
