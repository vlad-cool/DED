#include "test_equation.h"

int test_square_solver()
{
    double a = NAN;
    double b = NAN;
    double c = NAN;
    double x1 = NAN;
    double x2 = NAN;
    double expected_x1 = NAN;
    double expected_x2 = NAN;
    int n_roots = 0;
    int n_tests = 0;
    int n_errors = 0;
    int expected_n_roots = 0;
    int scanf_res = 0;
    FILE * fp = fopen("input.txt", "r");

    fscanf(fp, "%d", &n_tests);
    for (int i = 0; i < n_tests; i++)
    {
        if (input_square_equation_from_file(fp, &a, &b, &c, &expected_n_roots, &expected_x1, &expected_x2) == EOF)
        {
            return EOF;
        }
        x1 = NAN;
        x2 = NAN;
        n_roots = solve_square_equation(a, b, c, &x1, &x2);
        printf("-----Test #%d-----\n", i + 1);

        if (expected_n_roots != n_roots)
        {
            printf("%lfx^2 + %lfx + %lf = 0\n", a, b, c);
            printf("Incorrect number of roots, should be: %d, but it is %d\n", expected_n_roots, n_roots);
            n_errors++;
            continue;
        }

        if (expected_n_roots == NO_ROOTS || expected_n_roots == INF_ROOTS)
        {
            if (x1 == x1 || x2 == x2)
            {
                printf("%lfx^2 + %lfx + %lf = 0\n", a, b, c);
                printf("Expected no or inf roots, but variables were changed\n");
                n_errors++;
                continue;
            }

            x1 = 0;
            x2 = 0;
            n_roots = solve_square_equation(a, b, c, &x1, &x2);

            if (x1 != 0 || x2 != 0)
            {
                printf("%lfx^2 + %lfx + %lf = 0\n", a, b, c);
                printf("Expected no or inf roots, but variables were changed\n");
                n_errors++;
                continue;
            }
            continue;
        }

        if (!are_equal(x1, expected_x1))
        {
            printf("%lfx^2 + %lfx + %lf = 0\n", a, b, c);
            printf("Root isnt`t correct: should be %lf, but it is %lf\n", expected_x1, x1);
            n_errors++;
        }

        if (!are_equal(x2, expected_x2))
        {
            printf("%lfx^2 + %lfx + %lf = 0\n", a, b, c);
            printf("Root isnt`t correct: should be %lf, but it is %lf\n", expected_x2, x2);
            n_errors++;
        }
    }

    fclose(fp);
    printf("Number of errors: %d\n", n_errors);
    return(n_errors);
}
