// Binary Exponentiation
// Computation of Large Powers

// TC : O(log n)

#include <stdio.h>

double power(double x, int n)
{
    double ans = 1;
    long int N = n;
    if (N < 0)
        N = -1 * N;

    while (N)
    {
        if (N % 2 == 1)
        {
            ans = ans * x;
            N = N - 1;
        }

        else if (N % 2 == 0)
        {
            x = x * x;
            N = N / 2;
        }
    }

    if (n < 0)
        return (double)((1.0) / ans);

    return ans;
}

int main()
{
    double base;
    int exponent;

    printf("Enter the base: ");
    scanf("%lf", &base);

    printf("Enter the exponent: ");
    scanf("%d", &exponent);

    double result = power(base, exponent);
    printf("Result: %.2lf\n", result);

    return 0;
}
