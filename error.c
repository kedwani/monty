#include "monty.h"
#include <stdlib.h>
/**
 * error - Prints error messages based on error codes and exits the program
 * @a: Error code
 *
 * Return: void
 */
void error(int a)
{
	if (a == 1)
		fprintf(stderr, "USAGE: monty file\n");
	else if (a == 2)
		fprintf(stderr, "Error: Can't open file %s\n", v.argv);
	else if (a == 3)
		fprintf(stderr, "L%d: unknown instruction %s\n", v.l, v.tok);
	else if (a == 4)
		fprintf(stderr, "L%d: usage: push integer\n", v.l);
	else if (a == 5)
		fprintf(stderr, "Error: malloc failed\n");
	else if (a == 6)
		fprintf(stderr, "L%d: can't pint, stack empty\n", v.l);
	else if (a == 7)
		fprintf(stderr, "L%d: can't pop an empty stack\n", v.l);
	else if (a == 8)
		fprintf(stderr, "L%d: can't swap, stack too short\n", v.l);
	else if (a == 9)
		fprintf(stderr, "L%d: can't add, stack too short\n", v.l);
	else if (a == 10)
		fprintf(stderr, "L%d: can't sub, stack too short\n", v.l);
	else if (a == 11)
		fprintf(stderr, "L%d: can't div, stack too short\n", v.l);
	else if (a == 12)
		fprintf(stderr, "L%d: division by zero\n", v.l);

	if (a != 1 && a != 2)
		fclose(v.ptr);


	fre();
	exit(EXIT_FAILURE);
}
