#include "monty.h"
/**
 * main - Monty language interpreter entry point
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 *
 * Return: Exit status
 */

int main(int argc, char **argv)
{

	v.h = NULL;
	if (argc != 2)
		error(1);
	v.argv = argv[1];
	v.ptr = fopen(v.argv, "r");
	if (v.ptr == NULL)
		error(2);
	token();
	fclose(v.ptr);
	fre();
	return (0);
}
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
	if (a != 1 && a != 2)
		fclose(v.ptr);


	fre();
	exit(EXIT_FAILURE);
}
/**
 * push - Implements thy instruction, pushing a new element onto the stack
 *
 * Return: void
 */
void push(void)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (!new)
		error(5);
	new->n = v.d;
	new->prev = NULL;
	new->next = NULL;

	if (!v.h)
		v.h = new;
	else
	{
		new->next = v.h;
		v.h->prev = new;
		v.h = new;
	}
}
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
/**
 * fre - Frees memory allocated for the stack
 *
 * Return: void
 */
void fre(void)
{
	stack_t *tmp;

	tmp = v.h;
	while (v.h)
	{
		tmp = v.h->next;
		free(v.h);
		v.h = tmp;
	}
}
