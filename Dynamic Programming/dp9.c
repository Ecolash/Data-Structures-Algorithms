// Matrix Chain Multiplication
#include <stdio.h>
#include <string.h>
#include <math.h>

int MatrixChainOrder(int p[][2], int n)
{
    int DP[n + 1][n + 1];
    for (int i = 0; i <= n; i++)
        DP[i][i] = 0;

    // L is chain length.
    for (int L = 2; L <= n; L++)
    {
        for (int i = 1; i <= n - L + 1; i++)
        {
            int j = i + L - 1;
            DP[i][j] = __INT16_MAX__;
            for (int k = i; k <= j - 1; k++)
            {
                int temp = DP[i][k] + DP[k + 1][j] + p[i - 1][0] * p[k - 1][1] * p[j - 1][1];
                DP[i][j] = fmin(DP[i][j], temp);
            }
        }
    }
    return DP[1][n];
}

int main()
{
    int dim[][2] = {{3, 2}, {2, 4}, {4, 2}, {2, 5}};
    int size = sizeof(dim) / sizeof(dim[0]);

    printf("Minimum number of multiplications is %d ", MatrixChainOrder(dim, size));
    return 0;
}