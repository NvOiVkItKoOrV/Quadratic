#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <ctype.h>
#include"types.h"
#include"input.h"

void get_all_coefficients (coefficients *ptr_coeff)
{
    printf("Enter coefficient A:");
    reading_interface (&(ptr_coeff->a));

    printf("Enter coefficient B:");
    reading_interface (&(ptr_coeff->b));

    printf("Enter coefficient C:");
    reading_interface (&(ptr_coeff->c));
}

void reading_interface (double *ptr_to_one_coeff)
{
    assert (ptr_to_one_coeff);

    input_results status = INPUT_ERROR;

    while ((status = get_one_coefficient (ptr_to_one_coeff)) != INPUT_SUCCESS)
    {
        switch (status)
        {
        case INPUT_ERROR:
            printf("Something wrong. Please, try again:");
            break;

        case BUF_OVERFLOW_ERROR:
            printf("Buffer overflowed. Please, try again:");
            break;

        case TERMINAL_ERROR:
            printf("Command line has troubles. Please, try again:");
            break;

        case INPUT_SUCCESS:
            break;

        default:
            printf("x_x wtf?");
            break;
        }
    }
}

input_results get_one_coefficient (double *ptr_coeff)
{
    char buf[MAX_BUF_VAL] = {};
    int  symb_count       = 0;

    while((buf[symb_count] = getchar()) != '\n' && symb_count < MAX_BUF_VAL)
    symb_count++;

    if(buf[0] == '\0')
        return TERMINAL_ERROR;

    else if (symb_count >= MAX_BUF_VAL)
        return BUF_OVERFLOW_ERROR;

    else if(isdigit(*buf))
    {
        char * start         = buf;
        char * end           = buf + symb_count;
        int    whitespase_cl = 0;

        while(buf[whitespase_cl] == ' ')
        whitespase_cl++;

        start = buf + whitespase_cl;

        *ptr_coeff = strtod(start, &end);
        return INPUT_SUCCESS;
    }

    else
    return INPUT_ERROR;

}
