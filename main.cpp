#include <stdio.h>
#include <math.h>
#include <assert.h>


#include"types.h"
#include"input.h"
#include"quadratic_solver_func.h"
#include"output.h"
#include"unit_test.h"


int main()
{
    printf("\033[0;31m Hello!!!\033[0;33m");


    /*full_testing_func();*/

    coefficients coeffs = {};
    solutions    sol    = {};

    get_all_coefficients(&coeffs);
    quadratic_equation_solver(coeffs, &sol);
    output_coefficients(sol);

    return 0;
}
