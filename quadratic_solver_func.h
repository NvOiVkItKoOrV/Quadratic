#ifndef QUADR_SOLVER_H
#define QUADR_SOLVER_H

void   quadratic_equation_solver (coefficients set_of_numbers, solutions *roots);
void   line_equation_solver      (coefficients set_of_numbers, solutions *roots);
double discriminant_calculator   (coefficients set_of_numbers);
void   default_parameters        (solutions *roots);

const double EPSILON        = 0.00001;
const double DEFAULT_NUMBER = 0.0;

#endif /*QUADR_SOLVER_H*/

