//  Longest Common Subsequence

#include <stdio.h>
#include <string.h>
#include <math.h>

int lcs(char X[], char Y[], int m, int n)
{
    int DP[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                DP[i][j] = 0;

            else if (X[i - 1] == Y[j - 1])
                DP[i][j] = DP[i - 1][j - 1] + 1;

            else
                DP[i][j] = fmax(DP[i - 1][j], DP[i][j - 1]);
        }
    }

    int k = DP[m][n];
    char ans[k + 1];

    ans[k] = '\0';
    int i = m, j = n;

    while (i > 0 || j > 0)
    {
        if (X[i - 1] == Y[j - 1])
        {
            ans[k - 1] = X[i - 1];
            i--;
            j--;
            k--;
        }

        else if (DP[i - 1][j] >= DP[i][j - 1])
            i--;

        else
            j--;
    }

    printf("Longest Common Subsequence : ");
    printf("%s", ans);

    return DP[m][n];
}

int main()
{
    char S1[3005];
    char S2[3005];
    scanf("%s", S1);
    scanf("%s", S2);

    int m = strlen(S1);
    int n = strlen(S2);
    lcs(S1, S2, m, n);
    return 0;
}