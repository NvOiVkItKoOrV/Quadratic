#ifndef UNIT_TEST_H
#define UNIT_TEST_H

struct right_coefficients
{
    double right_a;
    double right_b;
    double right_c;
};

struct right_solutions
{
    double right_x1;
    double right_x2;
    int    right_num_of_roots;
};

const int ALL_PARAMETERS = 6;

void full_testing_func ();

int  check_parameters  (FILE *fp,
                        int *num_of_tests_passed,
                        int num_of_all_tests);

int  unit_test         (right_coefficients r_coeffs,
                        right_solutions r_sol,
                        int *num_of_tests_passed,
                        int num_of_all_tests);


#endif /* UNIT_TEST_H */
