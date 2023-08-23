#ifndef QUADR_SOLVER
#define QUADR_SOLVER

#include <stdio.h>
#include <math.h>
#include<assert.h>

struct coefficients
{
    double a;
    double b;
    double c;
};

struct solutions
{
    double x1;
    double x2;
    double discriminant;
    int    num_of_roots;
};

enum number_of_solutions
{
    ZERO_ROOTS =  0,
    ONE_ROOT   =  1,
    TWO_ROOTS  =  2,
    INF_ROOTS  = -1 //unusual number
};

void input_coefficients (coefficients *set_of_numbers);
void output_coefficients(solutions     roots         );

void quadratic_equation_solver(coefficients set_of_numbers, solutions *roots);
void line_equation_solver     (coefficients set_of_numbers, solutions *roots);

double discr_calculator(coefficients set_of_numbers);
#endif