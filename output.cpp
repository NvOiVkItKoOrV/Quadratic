#include <stdio.h>
#include "types.h"

void output_coefficients (const solutions roots)
{
    switch(roots.num_of_roots)
    {
    case ZERO_ROOTS:
        printf("No roots\n");
        break;

    case ONE_ROOT:
        printf("One root:%lf\n", roots.x1);
        break;

    case TWO_ROOTS:
        printf("Two roots:%lf %lf\n", roots.x1, roots.x2);
        break;

    case INF_ROOTS:
        printf("Infinity roots\n");
        break;

    default:
        fprintf(stderr, "Programm is died :(\n");
        break;
    }
}
