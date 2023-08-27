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
    int    right_n_roots;
};

const int ALL_PARAMETERS = 6;

void full_testing_func (const char *test_file_name);

int  check_parameters  (FILE *fp,
                        int *n_tests_passed,
                        int n_all_tests);

void  unit_test         (right_coefficients r_coeffs,
                        right_solutions r_sol,
                        int *n_tests_passed,
                        int n_all_tests);


#endif /* UNIT_TEST_H */
