// SIEVE OF ERATOSTHENES

#include <stdio.h>
#include <stdbool.h>

void sieveOfEratosthenes(int n)
{
    // Create a boolean array PRIME[0..n] and initialize all entries it as true.
    // A value in prime[i] will finally be false if i is Not a prime, else true.

    bool prime[n + 1];
    for (int i = 0; i <= n; ++i)
    {
        prime[i] = true;
    }

    for (int p = 2; p * p <= n; ++p)
    {
        // If prime[p] is not changed, then it is a prime.
        if (prime[p])
        {
            // Update all multiples of p.
            for (int i = p * p; i <= n; i += p)
            {
                prime[i] = false;
            }
        }
    }

    // Print all prime numbers.
    printf("Prime numbers up to %d are: ", n);
    for (int p = 2; p <= n; ++p)
    {
        if (prime[p])
        {
            printf("%d ", p);
        }
    }
}

int main()
{
    int n;
    printf("Enter the limit (n): ");
    scanf("%d", &n);

    sieveOfEratosthenes(n);
    return 0;
}
