#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "types.h"
#include "unit_test.h"
#include "quadratic_solver_func.h"

void full_testing_func (const char *test_file_name)
{
    assert(test_file_name);

    printf("Start testing...\n");

    int n_all_tests    = 1;
    int n_tests_passed = 0;

    FILE *test_file    = fopen(test_file_name, "r");

    if (!test_file)
    {
        fprintf(stderr, "Can't open test file!!!");
        return;
    }

    while (check_parameters(test_file, &n_tests_passed, n_all_tests))
        n_all_tests++;

    printf("----------------------------------------------------------------------------\n");
    printf("Number of all    tests - %d\n", n_all_tests - 1);
    printf("Number of passed tests - %d\n", n_tests_passed);
    printf("----------------------------------------------------------------------------\n");
}

int check_parameters (FILE *test_file, int *n_tests_passed, int n_all_tests)
{
    right_coefficients r_coeffs        = {};
    right_solutions    r_sol           = {};
    int                read_parameters = 0;

    read_parameters = fscanf(test_file, "%lg %lg %lg %lg %lg %d",
                             &(r_coeffs.right_a), &(r_coeffs.right_b), &(r_coeffs.right_c),
                             &(r_sol.right_x1),   &(r_sol.right_x2),   &(r_sol.right_n_roots));

    if (read_parameters != ALL_PARAMETERS)
        return 0;
    else
    {
        unit_test(r_coeffs, r_sol, n_tests_passed, n_all_tests);
        return 1;
    }
}

void unit_test (right_coefficients r_coeffs, right_solutions r_sol, int *n_tests_passed,
                                                                    int  n_all_tests)
{
    assert(n_tests_passed);

    coefficients coeffs = {};
    solutions sol       = {};

    coeffs.a = r_coeffs.right_a;
    coeffs.b = r_coeffs.right_b;
    coeffs.c = r_coeffs.right_c;

    quadratic_equation_solver(coeffs, &sol);

    if (is_equal(sol.x1,     r_sol.right_x1     ) &&
        is_equal(sol.x2,     r_sol.right_x2     ) &&
        is_equal(sol.n_roots,r_sol.right_n_roots))
    {
        // set_red_terminal_colour();
        printf("\033[0;32mTEST №%d is passed\033[0;37m\n", n_all_tests);
        // set_default_terminal_colour();
        *n_tests_passed += 1;
    }
    else
    {
        printf("\033[0;31mTEST №%d is failed\n\033[0;37m", n_all_tests);
        printf ("%lg %lg %d %lg %lg %d\n", sol.x1, sol.x2, sol.n_roots, r_sol.right_x1,
                                                           r_sol.right_x2,   r_sol.right_n_roots);
    }
}
