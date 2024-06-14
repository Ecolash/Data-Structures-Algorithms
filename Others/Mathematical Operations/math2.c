// Binary Exponentiation
// Effective Computation of large exponents modulo a number

// IDEA:
// -------------------------------------------------------------------
// (a x b) mod m = ((a mod m) x (b mod m)) mod m
// (a ^ 2) mod m = ((a mod m) ^ 2) mod m
// (a x b x c) mod m = ((a mod m) x (b mod m) x (c mod m)) mod m

#include <stdio.h>

typedef long long ll;

// Function to calculate (base^exponent) % modulus
ll power_mod(ll base, ll exponent, ll modulus)
{
    if (modulus == 1)
    {
        return 0; // Result is always 0 if modulus is 1
    }

    ll result = 1;

    while (exponent > 0)
    {
        base = base % modulus; // Reduce the base modulo to prevent overflow
        if (exponent % 2 == 1)
        {
            result = (result * base) % modulus;
        }
        base = (base * base);
        exponent /= 2;
    }

    return result;
}

int main()
{
    ll base, exponent, modulus;

    printf("Enter the base: ");
    scanf("%lld", &base);

    printf("Enter the exponent: ");
    scanf("%lld", &exponent);

    printf("Enter the modulus: ");
    scanf("%lld", &modulus);

    ll result = power_mod(base, exponent, modulus);
    printf("Result: %lld\n", result);

    return 0;
}
