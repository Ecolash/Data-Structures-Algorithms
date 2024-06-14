// Question_3:
// Fine the time complexity of the program:

int isPrime(int n)
{
    if (n == 1)
    {
        return 0;
    }
    for (int i = 2; i * i < n; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

// Verification of values of i from 2 to [n^0.5]
// T(n) proportional to n^0.5
// T(n) = n^0.5x k
// T(n) = O(n^0.5) where n = int n