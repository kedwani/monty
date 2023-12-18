#include "monty.h"
/**
 * pop - Removes the top element of the stack
 *
 * Description:
 * This function removes the node at the top of the stack. If the stack is not
 * empty, it adjusts the stack pointers and frees the memory of the removed
 * node. If the stack is already empty, it prints an error message.
 *
 * Global Variables:
 * - v.h: Points to the head of the stack.
 *
 * Error Handling:
 * If the stack is empty, it calls the error function with error code 7 to
 * print an error message and exit the program.
 */
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
