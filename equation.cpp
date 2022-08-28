#include "equation.h"

SolverResult solve_linear_equation(double a, double b, double *ptr_x)
{
    ASSERT(is_finite(a));
    ASSERT(is_finite(b));

    ASSERT(ptr_x != NULL);

    if (are_equal(a, 0))
    {
        return are_equal(b, 0) ? INF_ROOTS : NO_ROOTS;
    }
    else
    {
        *ptr_x = -b / a;
        return ONE_ROOT;
    }
}

SolverResult solve_true_square_equation(double a, double b, double c, double *ptr_x1, double *ptr_x2)
{
    ASSERT(is_finite(a));
    ASSERT(is_finite(b));
    ASSERT(is_finite(c));

    ASSERT(ptr_x1 != NULL);
    ASSERT(ptr_x2 != NULL);
    ASSERT(ptr_x1 != ptr_x2);

    ASSERT(!are_equal(a, 0));

    double discriminant = b * b - 4 * a * c;

    if (are_equal(discriminant, 0))
    {
        *ptr_x1 = -b / (2 * a);
        *ptr_x2 = -b / (2 * a);

        return ONE_ROOT;
    }

    if (discriminant > 0)
    {
        double sqrt_discriminant = sqrt(discriminant);
        *ptr_x1 = (-b - sqrt_discriminant) / (2 * a);
        *ptr_x2 = (-b + sqrt_discriminant) / (2 * a);
        sort(ptr_x1, ptr_x2);
        return TWO_ROOTS;
    }

    return NO_ROOTS;
}

SolverResult solve_square_equation(double a, double b, double c, double *ptr_x1, double *ptr_x2)
{
    ASSERT(is_finite(a));
    ASSERT(is_finite(b));
    ASSERT(is_finite(c));

    ASSERT(ptr_x1 != NULL);
    ASSERT(ptr_x2 != NULL);
    ASSERT(ptr_x1 != ptr_x2);

    double x = NAN;

    if (are_equal(a, 0))
    {
        SolverResult res = solve_linear_equation(b, c, &x);

        if (res == ONE_ROOT)
        {
            *ptr_x1 = x;
            *ptr_x2 = x;
        }

        return res;
    }

    // ax^2 + bx = 0
    if (are_equal(c, 0))
    {
        SolverResult res = solve_linear_equation(a, b, &x);

        switch (res)
        {
            case NO_ROOTS:
                *ptr_x1 = 0;
                *ptr_x2 = 0;
                return ONE_ROOT;

            case ONE_ROOT:
                if (are_equal(0, x))
                {
                    *ptr_x1 = 0;
                    *ptr_x2 = 0;
                    return ONE_ROOT;
                }
                else
                {
                    *ptr_x1 = 0;
                    *ptr_x2 = x;
                    sort(ptr_x1, ptr_x2);

                    return TWO_ROOTS;
                }

            case TWO_ROOTS:
                ASSERT(0);
                return NO_ROOTS;

            case INF_ROOTS:
                return INF_ROOTS;

            default:
                ASSERT(0);
                break;
        }
    }
    return solve_true_square_equation(a, b, c, ptr_x1, ptr_x2);
}
