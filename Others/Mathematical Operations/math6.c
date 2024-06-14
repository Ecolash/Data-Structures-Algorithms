// Modular Inverse

#include <stdio.h>

int gcdExtended(int a, int b, int *x, int *y);

int modInverse(int A, int M)
{
    int x, y;
    int g = gcdExtended(A, M, &x, &y);
    if (g != 1)
        return -1;

    else
    {
        int res = (x % M + M) % M;
        printf("Modular multiplicative inverse is %d", res);
        return res;
    }
}

int gcdExtended(int a, int b, int *x, int *y)
{
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }

    int x1, y1;
    int gcd = gcdExtended(b % a, a, &x1, &y1);

    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}

int main()
{
    int A = 3, M = 11;
    modInverse(A, M);
    return 0;
}
