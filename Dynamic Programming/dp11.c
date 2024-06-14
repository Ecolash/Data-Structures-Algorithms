// Shortest Common Supersequence
// Given two strings str1 and str2, the task is to find the shortest string that has both str1 and str2 as subsequences

// Length of the shortest common supersequence = (Sum of lengths of given two strings) - (Length of LCS of two given strings)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void SCS(char X[], char Y[], int m, int n)
{
    int DP[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                DP[i][j] = 0;
            }

            else if (X[i - 1] == Y[j - 1])
            {
                DP[i][j] = DP[i - 1][j - 1] + 1;
            }

            else
            {
                DP[i][j] = (DP[i - 1][j] > DP[i][j - 1]) ? DP[i - 1][j] : DP[i][j - 1];
            }
        }
    }
    int k = 0;
    int l = DP[m][n];
    char ans[m + n - l];

    int i = m, j = n;

    while (i > 0 || j > 0)
    {
        if (X[i - 1] == Y[j - 1])
        {
            ans[k++] = X[i - 1];
            i--;
            j--;
        }
        else if (DP[i][j] == DP[i][j - 1] && j >= 1)
        {
            ans[k++] = Y[j - 1];
            j--;
        }

        else
        {
            ans[k++] = X[i - 1];
            i--;
        }
    }

    k = k - 1;
    for (int i = k; i >= 0; i--)
    {
        printf("%c", ans[i]);
    }
    printf("\n");
}

int main()
{
    // INITIALISE 2 strings for the program as per the question
    char X[500];
    char Y[500];

    printf("Enter string X: ");
    scanf("%s", X);

    printf("Enter string Y: ");
    scanf("%s", Y);

    int m = strlen(X);
    int n = strlen(Y);

    // Call the function
    printf("Shortest common supersequence: ");
    SCS(X, Y, m, n);

    return 0;
}
