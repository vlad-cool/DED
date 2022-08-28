#include "equation_io.h"

void flush()
{
    while (getchar() != '\n');
}

int input_square_equation(double *ptr_a, double *ptr_b, double *ptr_c)
{
    ASSERT(ptr_a != NULL)
    ASSERT(ptr_b != NULL)
    ASSERT(ptr_c != NULL)
    ASSERT(ptr_a != ptr_b)
    ASSERT(ptr_b != ptr_c)
    ASSERT(ptr_c != ptr_a)

    int scanf_res = 0;
    char c = ' ';

    while (scanf_res != SQUARE_COEFF_COUNT || c != '\n')
    {
        scanf_res = scanf("%lf %lf %lf", ptr_a, ptr_b, ptr_c);
        scanf("%c", &c);

        if (scanf_res == EOF)
        {
            return EOF;
        }

        while (isspace(c) && c != '\n')
        {
            scanf("%c", &c);
        }

        if (scanf_res != SQUARE_COEFF_COUNT || c != '\n')
        {
            flush();
            printf("Incorrect input format, try again\n");
        }
    }

    return 0;
}

int input_square_equation_from_file(FILE *fp, double *ptr_a, double *ptr_b, double *ptr_c, int *ptr_n, double *ptr_x1, double *ptr_x2)
{
    ASSERT(fp != NULL)
    ASSERT(ptr_a != NULL)
    ASSERT(ptr_b != NULL)
    ASSERT(ptr_c != NULL)
    ASSERT(ptr_n != NULL)
    ASSERT(ptr_x1 != NULL)
    ASSERT(ptr_x2 != NULL)

    int scanf_res = 0;
    scanf_res = fscanf(fp, "%lf %lf %lf %d", ptr_a, ptr_b, ptr_c, ptr_n);

    if (scanf_res != 4)
    {
        printf("file reading error\n");
        return EOF;
    }

    switch (*ptr_n)
    {
        case ONE_ROOT:
            scanf_res = fscanf(fp, "%lf", ptr_x1);
            *ptr_x2 = *ptr_x1;

            if (scanf_res != 1)
            {
                printf("file reading error\n");
                fclose(fp);
                return EOF;
            }

            break;

        case TWO_ROOTS:
            scanf_res = fscanf(fp, "%lf %lf", ptr_x1, ptr_x2);

            if (scanf_res != 2)
            {
                printf("file reading error\n");
                return EOF;
            }

            break;
        default:
            break;
    }
    return 0;
}

void output_roots(SolverResult res, double *x)
{
    ASSERT(x != NULL)
    switch (res)
    {
        case NO_ROOTS:
            printf("This equation does not have real roots\n");
            break;
        case ONE_ROOT:
            printf("The root is: %lf\n", x[0]);
            break;
        case TWO_ROOTS:
            printf("The roots are: %lf, %lf\n", x[0], x[1]);
            break;
        case INF_ROOTS:
            printf("This equation has infinity amount of roots\n");
            break;
        default:
            ASSERT(0 && res);
            break;
    }
}
