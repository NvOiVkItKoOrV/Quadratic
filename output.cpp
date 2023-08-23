#include <stdio.h>
#include "types.h"

void output_coefficients (const solutions roots)
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
