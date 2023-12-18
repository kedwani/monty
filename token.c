#include "monty.h"

void token(void)
{
	int i;

	v.l = 1;
	while (fgets(v.line, sizeof(v.line), v.ptr) != NULL)
	{
		for (i = 0; v.line[i] != '\0'; ++i)
			if (v.line[i] == '\n')
				v.line[i] = '\0';
		v.tok = strtok(v.line, " ");
		if (v.tok == NULL || strcmp(v.tok, "nop") == 0)
		{
			++v.l;
			continue;
		}
		else if (strcmp(v.tok, "push") == 0)
		{
			v.dd = strtok(NULL, " ");
			if (v.dd == NULL)
				error(4);
			v.d = strtol(v.dd, &v.t, 10);
			if (*v.t != '\0')
				error(4);
			push();
		}
		else if (strcmp(v.tok, "pint") == 0)
			pint();
		else if (strcmp(v.tok, "pall") == 0)
			pall();
		else
			error(3);
		++v.l;
	}
}
void pint(void)
{
	if (v.h)
		printf("%d\n", v.h->n);
	else
		error(6);
}
