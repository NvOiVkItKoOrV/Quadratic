#include <stdio.h>
#include <assert.h>
#include <math.h>

#include"types.h"
#include"quadratic_solver_func.h"

void quadratic_equation_solver (const coefficients set_of_coeffs, solutions *roots)
{
    assert(roots);

    if (fabs(set_of_coeffs.a) <= EPSILON)
    {
        line_equation_solver (set_of_coeffs, roots);
    }
    else
    {
        roots->discriminant = discriminant_calculator (set_of_coeffs);

        if (roots->discriminant < -EPSILON)
        {
            default_parameters(roots);
            roots->num_of_roots = ZERO_ROOTS;
        }
        else if (fabs(roots->discriminant) <= EPSILON)
        {
            roots->x1 = -(set_of_coeffs.b) / (2 * set_of_coeffs.a);
            roots->x2 = DEFAULT_NUMBER;
            roots->num_of_roots = ONE_ROOT;
        }
        else if (roots->discriminant > EPSILON)
        {
            double sqrt_discriminant = sqrt(roots->discriminant);

            roots->x1 = (-(set_of_coeffs.b) - sqrt_discriminant) / (2 * set_of_coeffs.a);
            roots->x2 = (-(set_of_coeffs.b) + sqrt_discriminant) / (2 * set_of_coeffs.a);
            roots->num_of_roots = TWO_ROOTS;
        }
    }
}

void line_equation_solver (const coefficients set_of_coeffs, solutions *roots)
{
    assert(roots);

    if (fabs(set_of_coeffs.b) <= EPSILON)
    {
        if(fabs(set_of_coeffs.c) <= EPSILON)
        {
            default_parameters(roots);
            roots->num_of_roots = INF_ROOTS;
        }
        else
        {
            default_parameters(roots);
            roots->num_of_roots = ZERO_ROOTS;
        }
    }
    else
    {
    roots->x1           = -set_of_coeffs.c / set_of_coeffs.b;
    roots->x2           = roots->x1;
    roots->discriminant = DEFAULT_NUMBER;
    roots->num_of_roots = ONE_ROOT;
    }
}


double discriminant_calculator(const coefficients set_of_coeffs)
{
    return (set_of_coeffs.b * set_of_coeffs.b) - (4 * set_of_coeffs.a * set_of_coeffs.c);
}


void default_parameters(solutions *roots)
{
    assert(roots);

    roots->x1           = DEFAULT_NUMBER;
    roots->x2           = DEFAULT_NUMBER;
    roots->discriminant = DEFAULT_NUMBER;
}
