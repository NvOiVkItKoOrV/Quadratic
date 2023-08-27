#include <stdio.h>
#include <assert.h>
#include <math.h>

#include "types.h"
#include "quadratic_solver_func.h"

void quadratic_equation_solver (const coefficients set_of_coeffs, solutions *roots)
{
    assert(roots);

    const double A = set_of_coeffs.a;
    const double B = set_of_coeffs.b;
    const double C = set_of_coeffs.c;

    if (is_equal(A, 0.0))
    {
        line_equation_solver(set_of_coeffs, roots);
    }
    else
    {
        roots->discriminant = discriminant_calculator(A, B, C);

        if (is_less(roots->discriminant, 0.0))
        {
            roots->n_roots = ZERO_ROOTS;
        }
        else if (is_equal(roots->discriminant, 0.0))
        {
            roots->x1 = -B / (2 * A);
            roots->n_roots = ONE_ROOT;
        }
        else if (is_greater(roots->discriminant, 0.0))
        {
            double sqrt_discriminant = sqrt(roots->discriminant);

            roots->x1 = (-(B) - sqrt_discriminant) / (2 * A);
            roots->x2 = (-(B) + sqrt_discriminant) / (2 * A);
            roots->n_roots = TWO_ROOTS;
        }
    }
}

void line_equation_solver (const coefficients set_of_coeffs, solutions *roots)
{
    assert(roots);

    const double B = set_of_coeffs.b;
    const double C = set_of_coeffs.c;

    if (is_equal(B, 0.0))
    {
        if(is_equal(C, 0.0))
        {
            roots->n_roots = INF_ROOTS;
        }
        else
        {
            roots->n_roots = ZERO_ROOTS;
        }
    }
    else
    {
        roots->x1      = -C / B;
        roots->x2      = DEFAULT_NUMBER;
        roots->n_roots = ONE_ROOT;
    }
}

double discriminant_calculator (double A, double B, double C)
{
    return (B * B) - (4 * A * C);
}

int is_equal (double num1, double num2)
{
    if (fabs(num1 - num2) < EPSILON)
        return 1;
    else
        return 0;
}

int is_greater(double num1, double num2)
{
    if (is_equal(num1, num2) || num1 < num2)
        return 0;
    else
        return 1;
}

int is_less(double num1, double num2)
{
    if (is_equal(num1, num2) || num1 > num2)
        return 0;
    else
        return 1;
}
