#include "monty.h"
/**
 * pint - Prints the value at the top of the stack
 *
 * Description:
 * This function prints the integer value stored in the node at the top of the
 * stack. If the stack is empty, it prints an error message.
 *
 * Global Variables:
 * - v.h: Points to the head of the stack.
 *
 * Error Handling:
 * If the stack is empty, it calls the error function with error code 6 to
 * print an error message and exit the program.
 */
void pint(void)
{
	if (v.h)
		printf("%d\n", v.h->n);
	else
		error(6);
}
