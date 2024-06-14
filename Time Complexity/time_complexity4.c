// Question_4:
// Fine the time complexity of the program:

int isPrime(int n)
{
    for (int i = 2; i * i < 10000; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }

    return 1;
}
isPrime();

// Verification of values of i from 2 to 10000
// T(n) is not proportional to n
// T(n) = k
// T(n) = O(1) (constant time)