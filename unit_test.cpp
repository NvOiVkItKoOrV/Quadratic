#include<stdio.h>
#include<math.h>
#include<assert.h>
#include"types.h"
#include"unit_test.h"
#include"quadratic_solver_func.h"

void full_testing_func()
{
    printf("Start testing...\n");

    int num_of_all_tests    = 1;
    int num_of_tests_passed = 0;
    FILE *fp = fopen("TEST_PARAMETERS.txt", "r");

    while(check_parameters(fp, &num_of_tests_passed, num_of_all_tests))
    num_of_all_tests++;
    printf("----------------------------------------------------------------------------\n");
    printf("Number of all    tests - %d\n", num_of_all_tests - 1);
    printf("Number of passed tests - %d\n", num_of_tests_passed);
    printf("----------------------------------------------------------------------------\n");
}

int check_parameters(FILE *fp, int *num_of_tests_passed, int num_of_all_tests)
{
    right_coefficients r_coeffs = {};
    right_solutions    r_sol    = {};

    if(fscanf(fp, "%lg %lg %lg %lg %lg %d",
        &(r_coeffs.right_a), &(r_coeffs.right_b), &(r_coeffs.right_c),
        &(r_sol.right_x1),   &(r_sol.right_x2),   &(r_sol.right_num_of_roots) ) !=  ALL_PARAMETERS)
    return 0;
    else
    {
    unit_test(r_coeffs, r_sol, num_of_tests_passed, num_of_all_tests);
    return 1;
    }
}

int unit_test(right_coefficients r_coeffs,
              right_solutions r_sol,
              int *num_of_tests_passed,
              int num_of_all_tests)
{
    assert(num_of_tests_passed);

    coefficients coeffs = {};
    solutions sol       = {};

    coeffs.a = r_coeffs.right_a;
    coeffs.b = r_coeffs.right_b;
    coeffs.c = r_coeffs.right_c;

    quadratic_equation_solver(coeffs, &sol);

    if( sol.x1           == r_sol.right_x1 &&
        sol.x2           == r_sol.right_x2 &&
        sol.num_of_roots == r_sol.right_num_of_roots)
    {
        printf("TEST №%d is passed\n", num_of_all_tests);
        *num_of_tests_passed += 1;
    }
    else
    {
        printf("TEST №%d is failed\n", num_of_all_tests);
        printf ("%lg %lg %d %lg %lg %d\n", sol.x1, sol.x2, sol.num_of_roots, r_sol.right_x1, r_sol.right_x2, r_sol.right_num_of_roots);
    }

}
