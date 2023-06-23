#include "monty.h"

/**
 * use_err - function prompts usage error message
 * @flag: Error Type: 0 malloc failed, or 1 usage
 * Return: EXIT_FAILURE
*/

int use_err(int flag)
{
    char *errors[2] = {"Error: malloc failed", "USAGE: monty file"};
    
    fprintf(stderr, "%s\n", errors[flag]);
    return (EXIT_FAILURE);       
}

/**
 * open_err - function that prints file error message
 * @filename: file that failed to open
 * Return: EXIT_FAILURE
*/

int open_err(char *filename)
{
    fprintf(stderr, "Error: Can't open file %s\n", filename);
    return (EXIT_FAILURE);
}

/**
 * f_errs - error function
 * @flag: index to type error
 * @line_num1: number line with error
 * Return: EXIT_FAILURE
*/

int f_errs(int flag, unsigned int line_num1)
{
    char *errors[] = {"usage: push integer", "can\'t pint, stack empty",
        "can\'t pop an empty stack", "can\'t swap, stack too short",
        "can\'t add, stack too short", "can\'t sub, stack too short",
        "can\'t div, stack too short", "division by zero",
        "can\'t mul, stack too short", "can\'t mod, stack too short",
        "can\'t pchar, value out of range", "can\'t pchar, stack empty"};
    
    fprintf(stderr, "L%d: %s\n", line_num1, errors[flag]);
    return (EXIT_FAILURE);
}