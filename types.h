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
    ZERO_ROOTS =  0,
    ONE_ROOT   =  1,
    TWO_ROOTS  =  2,
    INF_ROOTS  = -1 //unusual number
};

typedef enum
{
    INPUT_ERROR,
    INPUT_SUCCESS,
    BUF_OVERFLOW_ERROR,
    EOF_ERROR,
} input_results;

#endif /*TYPES_H*/
