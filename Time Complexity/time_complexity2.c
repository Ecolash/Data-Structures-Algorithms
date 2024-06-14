// Question_2:
// Fine the time complexity of the program:

void func(int n)
{
    int sum = 0;
    int product = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d , %d\n", i, j);
        }
    }
}

// T(n) = n x (n x k1)
// T(n) = n^2 x k
// T(n) = O(n^2) where n = int n
