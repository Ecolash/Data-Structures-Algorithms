// LONGEST PALINDROMIC SUBSEQUENCE

/*

Given a string s, find the longest palindromic subsequence's length in s.
A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".

This question can be simply solved by using the LCS function.
We just define a string Y which is reverse of X.
Then the LCS of X and Y gives us the Longest Palindromic Subsequence present in X.

*/

#include <stdio.h>
#include <string.h>
#include <string.h>
#include <math.h>

int longestPalindromeSubseq(char *X)
{
    int n = strlen(X);
    char Y[n];

    for (int i = 0; i < n; i++)
        Y[n - 1 - i] = X[i];

    int DP[n + 1][n + 1];
    for (int i = 0; i <= n; i++)
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

    int k = DP[n][n];
    char ans[k + 1];

    ans[k] = '\0';
    int i = n, j = n;

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

    printf("LONGEST PALINDROMIC SUBSEQUENCE : ");
    printf("%s", ans);
    return DP[n][n];
}

int main()
{
    char s[] = "ccdcsdcsdc";
    int n = longestPalindromeSubseq(s);
    return 0;
}
