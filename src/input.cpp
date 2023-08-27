#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>

#include "../include/types.h"
#include "../include/input.h"
#include "../include/users_interface.h"

void get_all_coefficients (coefficients *ptr_coeff)
{
    assert(ptr_coeff);

    clear_stdin ();

    printf("Enter coefficient A: ");
    reading_interface (&(ptr_coeff->a));

    printf("Enter coefficient B: ");
    reading_interface (&(ptr_coeff->b));

    printf("Enter coefficient C: ");
    reading_interface (&(ptr_coeff->c));
    printf("---------------------------------------------------------------------------------\n");
}

void reading_interface (double *ptr_to_one_coeff)
{
    assert(ptr_to_one_coeff);

    input_results status = INPUT_ERROR;

    while ( (status = get_one_coefficient(ptr_to_one_coeff)) != INPUT_SUCCESS )
    {
        switch (status)
        {
        case INPUT_ERROR:
            printf("Something wrong. Please, try again: \n");
            break;

        case BUF_OVERFLOW_ERROR:
            printf("Buffer overflowed. Please, try again: \n");
            break;

        case TERMINAL_ERROR:
            printf("Command line has troubles. Please, try again: \n");
            break;

        case INPUT_SUCCESS:
            break;

        default:
            printf("x_x wtf?\n");
            break;
        }
    }
}

input_results get_one_coefficient (double *ptr_coeff)
{
    assert(ptr_coeff);

    char buf[MAX_BUF_VAL + 1] = {0};

    if(coeff_to_buf(buf, MAX_BUF_VAL))
    {
        return INPUT_ERROR;
    }


    if (buf[0] == '\0')
        return TERMINAL_ERROR;

    char *end = nullptr;

    double res = strtod(buf, &end);

    if (end == buf)
    {
        return INPUT_ERROR;
    }
    else if (errno == ERANGE)
    {
        errno = 0;
        return INPUT_ERROR; //OUT_OF_RANGE_ERROR;
    }
    else
    {
        *ptr_coeff = res;
        return INPUT_SUCCESS;
    }
}

int coeff_to_buf (char *buf, int size)
{
    assert(buf);

    int symb_count   = 0;
    int code_of_symb = 0;

    size -= 1;  // because of \0 at the end of buffer.

    while (symb_count < size && (code_of_symb = getchar()) != '\n')
    {
        buf[symb_count] = (char) code_of_symb;
        symb_count++;
    }

    if (code_of_symb != '\n')
    {
        clear_stdin();
        return 1;
    }
    else
    {
        buf[symb_count] = '\0';
        return 0;
    }

}
