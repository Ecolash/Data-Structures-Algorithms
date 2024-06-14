// FAST CALCULATION OF nCr

/*
-----------------------------
Time Complexity: O( R Log N)
Auxiliary Space: O(1)
-----------------------------
*/

#include <stdio.h>

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

void printNcR(int n, int r)
{

    // p holds the value of n*(n-1)*(n-2)...,
    // k holds the value of r*(r-1)...
    long long p = 1, k = 1;

    // C(n, r) == C(n, n-r),
    // choosing the smaller value
    if (n - r < r)
        r = n - r;

    if (r != 0)
    {
        while (r)
        {
            p *= n;
            k *= r;

            long long m = gcd(p, k);
            p /= m;
            k /= m;

            n--;
            r--;
        }
    }

    else
        p = 1;

    printf("%d \n", p);
}

int main()
{
    int n = 50, r = 25;
    printNcR(n, r);
    return 0;
}
