#ifndef QUADR_SOLVER_H
#define QUADR_SOLVER_H

void   quadratic_equation_solver (const coefficients *set_of_numbers, solutions *roots);
void   line_equation_solver      (const coefficients *set_of_numbers, solutions *roots);
double discriminant_calculator   (double A_coeff, double B_coeff, double C_coeff);
void   default_parameters        (solutions *roots);

int    is_equal                  (double num1, double num2);
int    is_greater                (double num1, double num2);
int    is_less                   (double num1, double num2);

const double EPSILON        = 0.00001;
const double DEFAULT_NUMBER = 0.0;

#endif /*QUADR_SOLVER_H*/

