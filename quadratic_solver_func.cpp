#include <stdio.h>
#include <assert.h>
#include <math.h>

#include"types.h"
#include"quadratic_solver_func.h"

void quadratic_equation_solver (const coefficients set_of_coeffs, solutions *roots)
{
    assert(roots);

    const double A = set_of_coeffs.a;//for making code more readable
    const double B = set_of_coeffs.b;
    const double C = set_of_coeffs.c;


    if ( sign_search(A) == ZERO_VALUE )
    {
        line_equation_solver (set_of_coeffs, roots);
    }
    else
    {
        roots->discriminant = discriminant_calculator (A, B, C);

        if ( sign_search(roots->discriminant) == NEGATIVE_VALUE )
        {
            roots->num_of_roots = ZERO_ROOTS;
        }
        else if ( sign_search(roots->discriminant) == ZERO_VALUE )
        {
            roots->x1 = -B / (2 * A);
            roots->num_of_roots = ONE_ROOT;
        }
        else if ( sign_search(roots->discriminant) == POSITIVE_VALUE )
        {
            double sqrt_discriminant = sqrt(roots->discriminant);

            roots->x1 = (-(B) - sqrt_discriminant) / (2 * A);
            roots->x2 = (-(B) + sqrt_discriminant) / (2 * A);
            roots->num_of_roots = TWO_ROOTS;
        }
    }
}

void line_equation_solver (const coefficients set_of_coeffs, solutions *roots)
{
    assert(roots);

    const double B = set_of_coeffs.b;
    const double C = set_of_coeffs.c;

    if ( sign_search(B) == 0 )
    {
        if( sign_search(C) == 0 )
        {
            roots->num_of_roots = INF_ROOTS;
        }
        else
        {
            roots->num_of_roots = ZERO_ROOTS;
        }
    }
    else
    {
        roots->x1           = -C / B;
        roots->x2           = roots->x1;
        roots->num_of_roots = ONE_ROOT;
    }
}


double discriminant_calculator(double A, double B, double C)
{
    return (B * B) - (4 * A * C);
}

int sign_search(double num)
{
    if ( fabs(num) < EPSILON )
        return ZERO_VALUE;

    else if( num < EPSILON && fabs(num) > EPSILON )
        return NEGATIVE_VALUE;

    else if( num > EPSILON && fabs(num) > EPSILON )
        return POSITIVE_VALUE;

    else
    {
        printf("Signum of the number can't be found");
        return MISTAKE_VALUE;
    }
}

