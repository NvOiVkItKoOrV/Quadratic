#include"quadratic_solver.h"

void input_coefficients(coefficients *set_of_numbers)
{
    assert(set_of_numbers != nullptr);
    /*printf("Enter coefficients a b c:\n");

    while( scanf("%lg %lg %lg", &(set_of_numbers->a), &(set_of_numbers->b), &(set_of_numbers->c)) != 3 )
    {
        scanf("%*[^\n]");
        printf("Uncorrectly entered, please, try again:");
    }*/
    int right_coeffs_count  = 3;
    int valid_coeff_counter = 0;

    do 
    {
        printf("Enter coefficients a b c:\n");
        valid_coeff_counter = scanf("%lg %lg %lg", &(set_of_numbers->a), &(set_of_numbers->b), &(set_of_numbers->c));
        printf("%d", valid_coeff_counter);
    }
    while(valid_coeff_counter != right_coeffs_count);

}

void quadratic_equation_solver(const coefficients set_of_numbers, solutions *roots)
{

    if (set_of_numbers.a == 0.0) 
    {
        line_equation_solver(set_of_numbers, roots);
    }
    else
    {
        roots->discriminant = discr_calculator(set_of_numbers);

        if (roots->discriminant < 0.0)
        {
            roots->x1           = 0.0;
            roots->x1           = 0.0;
            roots->num_of_roots = ZERO_ROOTS;            
        }
        else if (roots->discriminant == 0.0)
        {
            roots->x1 = -(set_of_numbers.b) / (2 * set_of_numbers.a);
            roots->x2 = 0.0;
            roots->num_of_roots = ONE_ROOT;
        }
        else if (roots->discriminant > 0.0)
        {
            roots->x1 = (-(set_of_numbers.b) - sqrt(roots->discriminant)) / (2 * set_of_numbers.a);
            roots->x2 = (-(set_of_numbers.b) + sqrt(roots->discriminant)) / (2 * set_of_numbers.a);
            roots->num_of_roots = TWO_ROOTS;
        }
    }
}

void line_equation_solver(const coefficients set_of_numbers, solutions *roots)
{
    if (set_of_numbers.b == 0.0)
    {
        if(set_of_numbers.c == 0.0)
        {
            roots->x1           = 0.0;
            roots->x2           = 0.0;
            roots->discriminant = 0.0;
            roots->num_of_roots = INF_ROOTS;
        }
        else
        {
            roots->x1           = 0.0;
            roots->x2           = 0.0;
            roots->discriminant = 0.0;
            roots->num_of_roots = ZERO_ROOTS;
        }
    }
    else
    {
    roots->x1           = (-set_of_numbers.c / set_of_numbers.b) ;
    roots->x2           = (roots->x1);
    roots->discriminant = 0.0;
    roots->num_of_roots = ONE_ROOT;
    }
}

void output_coefficients(const solutions roots)
{
    switch(roots.num_of_roots)
    {
    case 0:
        printf("No roots\n");
        break;

    case 1:
        printf("One root:%lf\n", roots.x1);
        break;

    case 2:
        printf("Two roots:%lf %lf\n", roots.x1, roots.x2);
        break;

    case (-1):
        printf("Infinity roots\n");
        break;

    default:
        printf("Programm is died :(\n");
        break;
    }
}

double discr_calculator(const coefficients set_of_numbers)
{
    return (set_of_numbers.b * set_of_numbers.b) - (4 * set_of_numbers.a * set_of_numbers.c);
}