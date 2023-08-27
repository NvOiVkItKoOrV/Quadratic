#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include "../include/types.h"
#include "../include/input.h"
#include "../include/users_interface.h"
#include "../include/output.h"
#include "../include/quadratic_solver_func.h"
#include "../include/unit_test.h"


void users_interface()
{
    command_to_do command_type = QUIT;

    printf("---------------------------------------------------------------------------------\n");
    printf("Hello!!! This is programm, which solves quadratic equation!\n");
    printf("---------------------------------------------------------------------------------\n");
    printf("There you can choose this commands:\n");

    all_commands();

    while ((command_type = get_command()) != QUIT)
    {
        switch (command_type)
        {
        case SOL_QUAD_EQ_PROG:
            solve_quad_prog();
            break;

        case COLOUR_OF_TERMINAL_CHANGE_PROG:
            colour_changer();
            break;

        case TESTING_PROG:
            full_testing_func(TEST_FILE_NAME);
            break;

        case ERROR:
            printf("This command not found\n");
            break;

        case HELP:
            all_commands();
            break;

        case QUIT:
            break;

        default:
            printf("Can't read the command\n");
            break;
        }
        all_commands();
    }
    printf("Programm is closed. Have a nice day!!!\n");
}

command_to_do get_command ()
{
    char buf[MAX_BUF_VAL] = {};

    scanf("%s", buf);

    char * buf_to_check = strtok(buf, " ");;

    char colour_command[]   = "colour";
    char test_command[]     = "test";
    char solve_sq_command[] = "solve";
    char quit_command[]     = "quit";
    char help_command[]     = "help";

    if( strcmp(buf_to_check, colour_command) == STR_CMP_SUCCESS )
        return COLOUR_OF_TERMINAL_CHANGE_PROG;

    else if( strcmp(buf_to_check, test_command) == STR_CMP_SUCCESS )
        return TESTING_PROG;

    else if( strcmp(buf_to_check, solve_sq_command) == STR_CMP_SUCCESS )
        return SOL_QUAD_EQ_PROG;

    else if( strcmp(buf_to_check, quit_command) == STR_CMP_SUCCESS )
        return QUIT;

    else if( strcmp(buf_to_check, help_command) == STR_CMP_SUCCESS )
        return HELP;

    else
        return ERROR;
}

void solve_quad_prog()
{
    coefficients coeffs = {};
    solutions    sol    = {};

    get_all_coefficients(&coeffs);
    quadratic_equation_solver(&coeffs, &sol);
    output_coefficients(&sol);
}

void colour_changer()
{
    printf("There are 3 commands for colours to change:\n");
    printf("red    - makes terminal letters red\n");
    printf("yellow - makes terminal letters yellow\n");
    printf("purple - makes terminal letters purple\n");
    printf("To make you terminal with default colour write anything,");
    printf("which is different from the previous commands!\n");

    colour col_of_terminal = get_new_colour();

    switch(col_of_terminal)
        {
        case RED:
            printf("\033[0;31m");
            break;

        case YELLOW:
            printf("\033[0;33m");
            break;

        case PURPLE:
            printf("\033[0;35m");
            break;

        case DEFAULT:
            printf("\033[0;37m");
            break;

        default:
            printf("Cannot change the colour\n");
            break;
        }

}

colour get_new_colour()
{
    char buf[MAX_BUF_VAL] = {};

    scanf("%s", buf);

    char *buf_to_check = buf;

    const char red_colour[]    = "red";
    const char yellow_colour[] = "yellow";
    const char purple_colour[] = "orange";

    if (strcmp(buf_to_check, red_colour) == STR_CMP_SUCCESS)
            return RED;

    else if (strcmp(buf_to_check, yellow_colour) == STR_CMP_SUCCESS)
            return YELLOW;

    else if (strcmp(buf_to_check, purple_colour) == STR_CMP_SUCCESS)
            return PURPLE;

    else
        return DEFAULT;
}

void all_commands()
{
    printf("---------------------------------------------------------------------------------\n");
    printf("colour - changes colour of terminal letters\n");
    printf("solve  - starts using the programm for solving quadratic equation\n");
    printf("test   - checks function quadratic equation function with TEST_PARAMETERS.txt\n");
    printf("help   - prints all command to use\n");
    printf("quit   - exits the program\n");
    printf("---------------------------------------------------------------------------------\n");
}

void clear_stdin ()
{
    int inappropriate_symbol = 0;

    while ((inappropriate_symbol = getchar ()) != '\n' && inappropriate_symbol != EOF);
}
