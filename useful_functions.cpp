#include "useful_functions.h"

int are_equal(double left, double right)
{
    const double eps = 1e-5;
    return fabs(left - right) < eps;
}

int is_finite(double d)
{
    //      isNaN                                 is INF
    return are_equal(d, d) && (!are_equal(d * 2, d) || !are_equal(d + 1, d));
}

int sort(double *ptr_1, double *ptr_2)
{
    if (*ptr_1 > *ptr_2)
    {
        double tmp = *ptr_1;
        *ptr_1 = *ptr_2;
        *ptr_2 = tmp;
        return 1;
    }
    return 0;
}
