// VARIOUS ALGORITHMS TO COMPUTE GCD

#include <stdio.h>

// BRUTE FORCE:

int gcd(int a, int b)
{
    int result = 1;
    for (int i = 1; i <= a && i <= b; i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            result = i;
        }
    }
    return result;
}

// EUCLIDIAN ALGORITHM:

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

// STEIN'S ALGORITHM (BINARY GCD COMPUTATION)

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    while (a != b)
    {
        if (a % 2 == 0)
            a /= 2;
        else if (b % 2 == 0)
            b /= 2;
        else if (a > b)
            a = (a - b) / 2;
        else
            b = (b - a) / 2;
    }

    return a; 
}


int main()
{
    int a = 48;
    int b = 18;
    printf("GCD of %d and %d is %d\n", a, b, gcd(a, b));
    return 0;
}
