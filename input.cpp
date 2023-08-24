#include <stdio.h>
#include <assert.h>
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

        case EOF_ERROR:
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
// TODO: Create your scan func using getchar
    assert(ptr_coeff != nullptr);

    scanf("%lg", ptr_coeff);
    return INPUT_SUCCESS;
}
