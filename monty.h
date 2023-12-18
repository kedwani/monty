#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct information - Structure to hold information for Monty interpreter
 * @argv: Command-line argument (file name)
 * @ptr: File pointer to the Monty script
 * @line: Buffer to store a line from the Monty script
 * @tok: Tokenized string obtained from strtok
 * @dd: Temporary string for storing tokenized values
 * @d: Integer value obtained from string conversion
 * @l: Line number in the Monty script
 * @h: Pointer to the head of the stack
 * @t: Temporary string for miscellaneous purposes
 *
 * Description:
 * This structure is used to hold various pieces of information needed for the
 * Monty language interpreter. It includes details about the script file,
 * individu lines, tokenization, numeric values, line numbers, stack handling,
 * and additional temporary strings and flags.
 */
typedef struct information
{
	char *argv;
	FILE *ptr;
	char line[1024];
	char *tok;
	char *dd;
	int d;
	int l;
	stack_t *h;
	char *t;
} info;
info v;


void error(int a);
void push(void);
void pall(void);
void fre(void);
void rmn(void);
void token(void);
void pint(void);
void pop(void);
void swap(void);
void add(void);
void sub(void);
void dev(void);
void mull(void);


#endif
