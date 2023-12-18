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
