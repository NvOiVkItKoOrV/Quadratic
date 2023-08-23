#include <stdio.h>
#include <math.h>
#include <assert.h>


#include"types.h"
#include"input.h"
#include"quadratic_solver_func.h"
#include"output.h"


int main()
{
    coefficients coeffs = {};
    solutions    sol    = {};

    get_all_coefficients( &coeffs);
    quadratic_equation_solver (coeffs, &sol);
    output_coefficients (sol);

    return 0;
}
