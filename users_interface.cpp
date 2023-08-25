#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include"types.h"
#include"input.h"
#include"users_interface.h"
#include"output.h"
#include"quadratic_solver_func.h"
#include"unit_test.h"


void users_interface()
{
    command_to_do command_type = QUIT;
    printf("Hello, this id my prog\n");

    while( ( command_type = get_command() ) != QUIT)
    {
        switch(command_type)
        {
        case SOL_QUAD_EQ_PROG:
            solve_quad_prog();
            break;
        case TESTING_PROG:
            full_testing_func();
            break;
        case ERROR:
            printf("This command not found");
            break;
        default:
            printf("Can't read the command");
            break;
        }

    }
}

command_to_do get_command()
{
/*    char buf[MAX_BUF_VAL] = {};
    int  symb_count       = 0;

    while((buf[symb_count] = getchar()) != '\n' && symb_count < MAX_BUF_VAL)
    symb_count++;

    buf[symb_count] = '\0';

    char * buf_to_check = buf;

    char * colour_command   = "colour";
    char * test_command     = "test";
    char * solve_sq_command = "solve";
    char * quit_command     = "quit";

    if(strcmp(buf_to_check, colour_command) == 0 )
        return COLOUR_OF_TERMINAL_CHANGE_PROG;

    else if( !strcmp(buf_to_check, test_command) == 0)
        */return TESTING_PROG;

    /*else if(!strcmp(buf_to_check, solve_sq_command) == 0)
        return SOL_QUAD_EQ_PROG;

    else if(!strcmp(buf_to_check, quit_command) == 0)
        return QUIT;

    else
        return ERROR;*/
}

void solve_quad_prog()
{
    coefficients coeffs = {};
    solutions    sol    = {};

    get_all_coefficients(&coeffs);
    quadratic_equation_solver(coeffs, &sol);
    output_coefficients(sol);
}

