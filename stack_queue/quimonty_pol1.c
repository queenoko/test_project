#include "monty.h"

/**
 * quimont_pinq - function that prints top value of stack
 * @stack: Pointer to stack list
 * @line_num1: current working line number of Monty Bytecode file
*/

void quimont_pinq(stack_t **stack, unsigned int line_num1)
{
    stack_t *temp = *stack;

    if (!temp)
    {
        f_errs(1, line_num1);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", temp->n);
}

/**
 * quimont_popq - function that removes top value from the stack
 * @stack: pointerto stack_t list
 * @line_num1: line number of Monty bytcode file
 */

void quimont_popq(stack_t **stack, unsigned int line_num1)
{
    stack_t *temp = *stack;

    if (!temp)
    {
        f_errs(2, line_num1);
        exit(EXIT_FAILURE);
    }

    if (temp->next)
            temp->next->prev = temp->prev;
    *stack = temp->next;
    free(temp);

}

/**
 * quimont_swapq - function that swap two values at the top of the stack
 * @stack: pointer to the top of the stack
 * @line_num1: line number of Monty byte code file
*/

void quimont_swapq(stack_t **stack, unsigned int line_num1)
{
    int temp;
    if (*stack == NULL || (*stack)->next == NULL)
    {
        f_errs(3, line_num1);
        exit(EXIT_FAILURE);
    }
    temp = (*stack)->next->n;
    (*stack)->next->n = (*stack)->n;
    (*stack)->n = temp;
}

/**
 * quimont_addq - function which adds two top value of stack
 * @stack: pointer to the stack list
 * @line_num1: Line number of Monty bytecode file
 * Desc: Result is stored in second value node
 * from top and top value is removed
*/

void quimont_addq(stack_t **stack, unsigned int line_num1)
{
    int temp;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        f_errs(4, line_num1);
        exit(EXIT_FAILURE);
    }
    temp = (*stack)->n + (*stack)->next->n;
    (*stack)->next->n = temp;
    quimont_popq(stack, line_num1);
}

/**
 * quimont_subq - function that subtracts second value from top linked list
 * @stack: pointer to stack list
 * @line_num1: line number of monty bytecode file
 * Desc: second node is stored at the top and the top value is removed
*/

void quimont_subq(stack_t **stack, unsigned int line_num1)
{
    int temp;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        f_errs(5, line_num1);
        exit(EXIT_FAILURE);
    }
    temp = (*stack)->next->n - (*stack)->n;
    (*stack)->next->n = temp;
    quimont_popq(stack, line_num1);
}