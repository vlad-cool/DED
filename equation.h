#ifndef __equation_h_
#define __equation_h_

#include <math.h>
#include "useful_functions.h"

enum SolverResult
{
    INF_ROOTS  = -1,
    NO_ROOTS   =  0,
    ONE_ROOT   =  1,
    TWO_ROOTS  =  2
};

//! @param [in] a coefficient at x
//! @param [in] b free coefficient
//! @param [out] x root
//! @return number of roots or INF_ROOTS
SolverResult solve_linear_equation(double a, double b, double *ptr_x);

//! @param [in] a coefficient at x^2
//! @param [in] b coefficient at x
//! @param [in] c free coefficient
//! @param [out] x1 lesser or equal root
//! @param [out] x2 higher or equal root
//! @return number of roots
//! @note a should not be equal to zero, if you aren`t sure use solve_square_equation() instead
SolverResult solve_true_square_equation(double a, double b, double c, double *ptr_x1, double *ptr_x2);

//! @param [in] a coefficient at x^2
//! @param [in] b coefficient at x
//! @param [in] c free coefficient
//! @param [out] x1 lesser or equal root
//! @param [out] x2 higher or equal root
//! @return number of roots or INF_ROOTS
SolverResult solve_square_equation(double a, double b, double c, double *ptr_x1, double *ptr_x2);

#endif
