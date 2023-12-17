#include "monty.h"
info v;

int main(int argc,char **argv)
{
	v.h = NULL;

	if (argc != 2)
		error(1);
	v.argv = argv[1];
	v.ptr = fopen(v.argv, "r");
	if (v.ptr == NULL)
		error(2);
	v.l = 1;
	while(fgets(v.line,sizeof(v.line),v.ptr) != NULL)
	{
		v.tok = strtok(v.line," ");

		if (strcmp(v.tok,"push") == 0)
		{
			if (!(v.d = atoi(strtok(NULL, " "))))
				error(4);
			push();

		}
		else if (strcmp(v.tok,"pall") == 0)
			pall();
		else error(3);
		++v.l;
	}
	fclose(v.ptr);
	return(0);
}

void error(int a)
{
	if (a == 1)
		fprintf(stderr,"USAGE: monty file\n");
	else if (a == 2)
		fprintf(stderr,"Error: Can't open file %s\n",v.argv);
	else if (a == 3)
		fprintf(stderr,"L%d: unknown instruction\n",v.l);
	else if (a == 4)
		fprintf(stderr,"L%d: usage: push integer\n",v.l);
	else if (a == 5)
		fprintf(stderr,"Error: malloc failed\n");


	exit(EXIT_FAILURE);
}
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

void pall(void)
{
	while(v.h)
	{
		printf("%d\n",v.h->n);
		v.h = v.h->next;
	}
}