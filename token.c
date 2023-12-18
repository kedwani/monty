#include "monty.h"
/**
 * token - Tokenizes Monty script lines and executes corresponding commands
 *
 * Description:
 * This function reads lines from the Monty script, tokenizes each line, and
 * executes the corresponding Monty commands. Supported commands include:
 *   - push: Pushes an integer onto the stack
 *   - pall: Prints all elements of the stack
 *   - pint: Prints the value at the top of the stack
 *   - pop: Removes the top element of the stack
 *   - swap: Swaps the top two elements of the stack
 *   - add: Adds the top two elements of the stack
 *   - nop: No operation (skips line)
 * If script contains invalid or unknown commands, it prints an error message
 * and exits the program.
 *
 * Global Variables:
 * - v.l: Line number in the Monty script
 * - v.line: Buffer to store a line from the Monty script
 * - v.tok: Tokenized string obtained from strtok
 * - v.dd: Temporary string for storing tokenized values
 * - v.d: Integer value obtained from string conversion
 * - v.t: Temporary string for miscellaneous purposes
 * - v.ptr: File pointer to the Monty script
 *
 * Error Handling:
 * If a command encounters an error (e.g., invalid argument for push, unknown
 * command), it calls the error function to print an error message and exit the
 * program.
 */
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
		if (v.tok == NULL || strcmp(v.tok, "nop") == 0 || v.tok[0] == '#')
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
		else if (strcmp(v.tok, "pall") == 0)
			pall();
		else if (strcmp(v.tok, "pint") == 0)
			pint();
		else if (strcmp(v.tok, "pop") == 0)
			pop();
		else if (strcmp(v.tok, "swap") == 0)
			swap();
		else if (strcmp(v.tok, "add") == 0)
			add();
		else if (strcmp(v.tok, "sub") == 0)
			sub();
		else
			error(3);
		++v.l;
	}
}
