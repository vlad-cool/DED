#include <stdio.h>
#include <math.h>
#include <assert.h>

int max(int left, int right)
{
    return left > right ? left : right;
}

int main()
{
    int a[3] = {0, 0, 0}; //coefficients of ecuasion (a[0]*x^2 + a[1]*x + a[2] = 0)
    int val = 0, sign = 1, pow = 0; //abs and sign of currently entering number
                                    //and power of x
    double d; //discriminant
    char c;

    printf("enter valid square equation with integer coefficients and leading numbers\n");

    while (c != '\n')
    {
        scanf("%c", & c);
        if (c == '-')
        {
            if (pow > 0)
            {
                val = max(val, 1);
            }
            a[2 - pow] += val * sign;
            val = 0;
            sign = -1;
            pow = 0;
            continue;
        }
        if (c == '+')
        {
            if (pow > 0)
            {
                val = max(val, 1);
            }
            a[2 - pow] += val * sign;
            val = 0;
            sign = 1;
            pow = 0;
            sign = 1;
            continue;
        }
        if (c >= '0' && c <= '9')
        {
            val *= 10;
            val += c - '0';
        }
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            pow++;
        }
        if (c == '^')
        {
            while (c < '0' || c > '2')
            {
                scanf("%c", & c);
            }
            pow += c - '1';
        }
        if (c == '=')
        {
            if (pow > 0)
            {
                val = max(val, 1);
            }
            a[2 - pow] += val * sign;
            val = 0;
            sign = 1;
            pow = 0;
            a[0] *= -1;
            a[1] *= -1;
            a[2] *= -1;
        }
    }

    a[2 - pow] += val * sign;
    val = 0;
    sign = 1;
    pow = 0;

    //printf("a: %d, b: %d, c: %d\n", a[0], a[1], a[2]);

    d = a[1] * a[1] - 4 * a[0] * a[2];
    if (a[0] == 0 && a[1] != 0)
    {
        printf("this equation is not square, but it`s root is: %d\n", (double)-a[2] / a[1]);
    }
    else if (d < 0 || (a[0] == 0 && a[1] == 0))
    {
        printf("this equation does not have real roots\n");
    }
    else if (d == 0)
    {
        printf("the root is: %f\n", (double)-a[1] / (2 * a[0]));
    }
    else
    {
        printf("the roots are: %f, %f\n", (-a[1] - sqrt(d)) / (2 * a[0]), (-a[1] + sqrt(d)) / (2 * a[0]));
    }
}
