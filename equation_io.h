#ifndef __equation_io_h_
#define __equation_io_h_

#include <stdio.h>
#include <string.h>
#include "equation.h"
#include "useful_functions.h"

enum EquationCoefficients {
    SQUARE_COEFF_COUNT = 3
};

//! @brief flushes input buffer
void flush();

//! @param [in] c char to check
//! @return 1 if c is whitespace newline or something like that else 0
int is_allowed(char c);

//! @param [in] ptr_a pointer to coefficient at x^2
//! @param [in] ptr_b pointer to coefficient at x
//! @param [in] ptr_c pointer to free coefficient
//! @return EOF if error occured else 0
int input_square_equation(double *ptr_a, double *ptr_b, double *ptr_c);

//! @param [in] fp pointer to file read from
//! @param [out] ptr_b pointer to coefficient at x
//! @param [out] ptr_c pointer to free coefficient
//! @param [out] ptr_a pointer to coefficient at x^2
//! @param [out] ptr_n pointer to number of roots
//! @param [out] ptr_x1 pointer to first root
//! @param [out] ptr_x2 pointer to second root
//! @return EOF if error occured else 0
int input_square_equation_from_file(FILE *fp, double *ptr_a, double *ptr_b, double *ptr_c, int *ptr_n, double *ptr_x1, double *ptr_x2);

//! @param [in] n number of roots
//! @param [in] x array of roots
//! @note n should be greater or equal than length of x
void output_roots(SolverResult n, double* x);

#endif
