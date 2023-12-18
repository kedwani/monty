#include "monty.h"
/**
 * pall - Implemy instruction, printing all elements intack.
 *
 * Return: void
 */
void pall(void)
{
	stack_t *tmp = v.h;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
