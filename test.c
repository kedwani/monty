#include "monty.h"
int main(int argc,char **argv)
{
	FILE *ptr;
	FILE *err = stderr;
	char line[1024];

	if (argc != 2)
	{
		fprintf(err,"USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	ptr = fopen(argv[1],"r");
	if (ptr == NULL)
	{
		fprintf(err,"Error: Can't open file %s\n",argv[1]);
		exit(EXIT_FAILURE);
	}

	fgets(line,sizeof(line),ptr);
	printf("%s/n",line);
	printf("$test$");
	fclose(ptr);
	return(0);

}
