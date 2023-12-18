#include "monty.h"
/**
 * mod - Computes the remainder of the division of the second element
 *       by the top element in the stack.
 *
 * If the stack contains less than two elements, or if the top element
 * (divisor) is zero, it triggers an error.
 *
 * Description:
 * - The remainder of the division of the second element by the top element
 *   is stored as the new value of the second element.
 * - The top element is removed from the stack.
 * - If successful, frees the memory of the removed top element.
 *
 * @note:This function handles division by zero and insufficient stack elements.
 */
void mod(void)
{
	if (v.h && v.h->next)
	{
		if (v.h->n == 0)
			error(12);
		v.h->next->n %= v.h->n;
		v.h = v.h->next;
		free(v.h->prev);
		v.h->prev = NULL;
	}
	else
		error(14);
}
