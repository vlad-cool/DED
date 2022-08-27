#include "useful_functions.h"

int is_finite(double d)
{
    //      isNaN                is INF
    return (d == d) && (d * 2 != d || d + 1 != d);
}

int are_equal(double left, double right)
{
    const double eps = 0.00001;
    return fabs(left - right) < eps;
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
