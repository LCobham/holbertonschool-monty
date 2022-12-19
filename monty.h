#ifndef MONTY_H
#define MONTY_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct global_s - strcture to store file pointer and buffer to free
 * in case of exit
 * @filePtr: file pointer
 * @getlineBuffer: string from getline
 * @mode: insertion mode (1 for stack mode, 0 for queue mode)
 */
typedef struct global_s
{
	FILE *filePtr;
	char *getlineBuffer;
	int mode; /* 1 = stack mode; 0 = queue mode */
} global_t;

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
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/* Global Variables */
extern global_t global;


/* Function Prototypes */
void pushF(stack_t **stack, unsigned int line_number);
int insertNode(stack_t **stack, int value);
int freeStack(stack_t *stack);
void pallF(stack_t **stack, unsigned int __attribute__ ((unused)) line_number);
void (*getOcd(stack_t **s, char *t, unsigned int l))(stack_t **, unsigned int);
void swap_function(stack_t **tail, unsigned int line_number);
void pintF(stack_t **stack, unsigned int __attribute__ ((unused)) line_number);
void pop_function(stack_t **tail, unsigned int line_number);
void add_function(stack_t **tail, unsigned int line_number);
void nop_function(stack_t **tail, unsigned int line_number);
void subF(stack_t **stack, unsigned int line_number);
void divF(stack_t **stack, unsigned int line_number);
void mulF(stack_t **stack, unsigned int line_number);
void modF(stack_t **stack, unsigned int line_number);
void pcharF(stack_t **stack, unsigned int line_number);
void pstrF(stack_t **stack, unsigned int __attribute__ ((unused)) line_number);
void rotlF(stack_t **stack, unsigned int __attribute__ ((unused)) line_number);
void rotrF(stack_t **stack, unsigned int __attribute__ ((unused)) line_number);
int insertQueueNode(stack_t **stack, int value);

#endif
