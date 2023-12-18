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
	int i = 0;

	v.h = NULL;
	if (argc != 2)
		error(1);
	v.argv = argv[1];
	v.ptr = fopen(v.argv, "r");
	if (v.ptr == NULL)
		error(2);
	v.l = 1;
	while (fgets(v.line, sizeof(v.line), v.ptr) != NULL)
	{
		for (; v.line[i] != '\0'; ++i)
			if (v.line[i] == '\n')
				v.line[i] = '\0';
		v.tok = strtok(v.line, " ");
		if (v.tok == NULL)
		{
			++v.l;
			continue;
		}
		if (strcmp(v.tok, "push") == 0)
		{
			v.dd = strtok(NULL, " ");
			if ((v.dd == NULL)
				error(4);
			v.d = atoi(v.dd);
			if (v.d  == 0)
				error(4);
			push();
		}
		else if (strcmp(v.tok, "pall") == 0)
			pall();
		else
			error(3);
		++v.l;
	}
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
		fprintf(stderr, "L%d: unknown instruction\n", v.l);
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
 * push - Implements the push Monty in, pushing a new element onto the stack
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
 * pall - Implements the pall Monty intion, printing all elements in the stack
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
