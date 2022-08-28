#include <stdio.h>

#include "equation.h"
#include "equation_io.h"
#include "test_equation.h"
#include "useful_functions.h"

int main()
{
    double a = NAN;
    double b = NAN;
    double c = NAN;
    double roots[2] = {NAN, NAN};
    int command = ' ';
    SolverResult n_roots = NO_ROOTS;

    printf("Press e for solving equation, t for autotests or q to quit\n");

    while ((command = getchar()) != 'q')
    {
        switch (command)
        {
            case 'e':
                printf("Enter coefficients of square equation\n");

                if (input_square_equation(&a, &b, &c) == EOF)
                {
                    return 1;
                }

                n_roots = solve_square_equation(a, b, c, roots, roots + 1);
                output_roots(n_roots, roots);

                break;
            case 't':
                test_square_solver();
                break;
            case 'h':
                printf("Press e for solving equation, t for autotests or q to quit\n");
                break;
            case '\n':
                break;
            case EOF:
                return 0;
                break;
            default:
                printf("Unknown command!\n");
                printf("Press e for solving equation, t for autotests or q to quit\n");
                break;
        }
    }
    return 0;
}
