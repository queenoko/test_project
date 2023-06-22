#include "monty.h"

/**
 * main - Monty Interpreter entry function
 * @arc: Number of argument count
 * @arv: Array of inputed arguments
 * Return: 0 on success
*/
int main(int arc, char **arv)
{
    FILE *fd = NULL;
    int exit_stat = EXIT_SUCCESS;

    if (arc != 2)
            return (use_err(1));

    fd = fopen(arv[1], "r");
    if (fd == NULL)
            return (open_err(arv[1]));

    exit_stat = quimont_run(fd);
    fclose(fd);
    return (exit_stat);
            open_err(arv[1]);
    quimont_run(fd);
    exit(EXIT_SUCCESS);
    return (0);
}