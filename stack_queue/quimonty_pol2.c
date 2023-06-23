#include "monty.h"

/**
 * quimont_mul - function multiplies two top values in a stack
 * @stack: pointer to stack list
 * @line_num2: line number of monty byte codes file
 * Desc: Result is stored in second value node fron top and the top
 * value is removed
*/

void quimont_mul(stack_t **stack, unsigned int line_num2)
{
    int tempy;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        f_errs(8, line_num2);
        exit(EXIT_FAILURE);
    }
    tempy = (*stack)->n * (*stack)->next->n;
    (*stack)->next->n = tempy;
    quimont_popq(stack, line_num2);
}

/**
 * quimont_div - function that divides the second value at the top of
 * a stack linked by top value
 * @stack: pointer to stack list
 * @line_num2: line number of monty bytecode file
 * @desc: Result is stored in second node at the top and
 * top value value is removed
*/

void quimont_div(stack_t **stack, unsigned int line_num2)
{
    int tempy;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        f_errs(6, line_num2);
        exit(EXIT_FAILURE);
    }
    if ((*stack)->n == 0)
    {
        f_errs(7, line_num2);
        exit (EXIT_FAILURE);
    }
    tempy = (*stack)->next->n / (*stack)->n;
    (*stack)->next->n = tempy;
    quimont_popq(stack, line_num2);
}

/**
 * quimont_mod - function that mods second value from top of
 * stack linked by top value
 * @stack: pointer to stack list
 * @line_num2: line number of monty bytecode
 * Desc: Result is stored in second node from top and top value is removed
*/

void quimont_mod(stack_t **stack, unsigned int line_num2)
{
    int tempy;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        f_errs(9, line_num2);
        exit(EXIT_FAILURE);
    }
    if ((*stack)->n == 0)
    {
        f_errs(7, line_num2);
        exit(EXIT_FAILURE);
    }
    tempy = (*stack)->next->n % (*stack)->n;
    (*stack)->next->n = tempy;
    quimont_popq(stack, line_num2);
}

/**
 * quimont_pchar - function that prints char at top value of stack
 * @stack: pointer to stack list
 * @line_num2: current line number of monty bytecode file
*/

void quimont_pchar(stack_t **stack, unsigned int line_num2)
{
    int num0 = 0;
    stack_t *tempy = *stack;

    if (!tempy)
    {
        f_errs(11, line_num2);
        exit(EXIT_FAILURE);
    }
    num0 = tempy->n;
    if (num0 < 0 || num0 > 127)
    {
        f_errs(10, line_num2);
        exit(EXIT_FAILURE);
    }
    printf("%c\n", tempy->n);
}

/**
 * quimont_pstr - function that prints string starting from top of stack,
 * followed by new line
 * @stack: Pointer to stack list
 * @line_num2: present line number of monty bytecode file
*/

void quimont_pstr(stack_t **stack, unsigned int line_num2)
{
    stack_t *tempy = *stack;
    (void)line_num2;

    if (stack == NULL || *stack == NULL)
    {
        printf("|n");
        return;
    }
    while (tempy != NULL)
    {
        if (tempy->n > 0 && tempy->n <= 127)
        {
            printf("%c", tempy->n);
            tempy = tempy->next;
        }
        else
        {
            break;
        }
    }
    printf("\n");
    
}