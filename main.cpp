#include"quadratic_solver.h"

int main()
{
    printf("Hello!!!");
    coefficients coeffs = {};
    solutions    sol = {};

    input_coefficients(&coeffs);
    quadratic_equation_solver(coeffs, &sol);
    output_coefficients(sol);

    return 0;
}
