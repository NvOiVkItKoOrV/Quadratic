#ifndef TYPES_H
#define TYPES_H

struct coefficients
{
    double a;
    double b;
    double c;
};

struct solutions
{
    double x1;
    double x2;
    double discriminant;
    int    num_of_roots;
};

enum number_of_solutions
{
    ZERO_ROOTS,
    ONE_ROOT,
    TWO_ROOTS,
    INF_ROOTS
};

typedef enum
{
    INPUT_ERROR,
    INPUT_SUCCESS,
    BUF_OVERFLOW_ERROR,
    TERMINAL_ERROR,
} input_results;

enum signum_values
{
    NEGATIVE_VALUE = -1,
    ZERO_VALUE     =  0,
    POSITIVE_VALUE =  1,
    MISTAKE_VALUE  =  2
};

typedef enum
{
SOL_QUAD_EQ_PROG,
TESTING_PROG,
COLOUR_OF_TERMINAL_CHANGE_PROG,
ERROR,
QUIT,
}command_to_do;

#endif /*TYPES_H*/
