#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

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

/* quimonty_main.c*/
int main(int arc, char **arv);

/* quimonty_fre.c*/
int quimont_run(FILE *fd);
char **quitoken(char *line, char *delim);
int quiempty_line(char *line, char *delimss);

/* quimonty_exev.c*/
int quiexec(char **tokenq, stack_t **stack, unsigned int line_num1);
int quimont_push(stack_t **stack, char **tokenq, unsigned int line_num1);
int quimont_pushq(stack_t **stack, char **tokenq, unsigned int line_num1);
void quimont_pall(stack_t **stack, unsigned int line_num1);

/* quimonty_pol1.c*/
void quimont_pinq(stack_t **stack, unsigned int line_num1);
void quimont_popq(stack_t **stack, unsigned int line_num1);
void quimont_swapq(stack_t **stack, unsigned int line_num1);
void quimont_subq(stack_t **stack, unsigned int line_num1);
void quimont_addq(stack_t **stack, unsigned int line_num1);

/* quimonty_pol2.c*/
void quimont_mul(stack_t **stack, unsigned int line_num2);
void quimont_div(stack_t **stack, unsigned int line_num2);
void quimont_mod(stack_t **stack, unsigned int line_num2);
void quimont_pchar(stack_t **stack, unsigned int line_num2);
void quimont_pstr(stack_t **stack, unsigned int line_num2);

/* quimonty_pol3.c*/
void quimont_rot1(stack_t **stack, unsigned int line_num2);
void quimont_rotr(stack_t **stack, unsigned int line_num2);

/*quimonty_errors.c*/
int use_err(int flag);
int open_err(char *filename);
int f_errs(int flag, unsigned int line_num1);


#endif