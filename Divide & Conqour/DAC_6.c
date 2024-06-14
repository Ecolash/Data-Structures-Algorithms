// Longest Common Prefix

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *common(char *a, char *b)
{
    int lenA = strlen(a);
    int lenB = strlen(b);
    int minLen = lenA < lenB ? lenA : lenB;

    char *result = (char *)malloc(minLen + 1);
    int i;

    for (i = 0; i < minLen && a[i] == b[i]; i++)
    {
        result[i] = a[i];
    }

    result[i] = '\0';
    return result;
}

char *LCP(char *s[], int l, int r)
{
    if (l == r)
        return s[l];

    int m = (l + r) / 2;
    char *left = LCP(s, l, m);
    char *right = LCP(s, m + 1, r);
    char *ans = common(left, right);
    return ans;
}

int main()
{
    char *strs[] = {"geeksforgeeks", "geeks", "geek", "geeker"};
    int n = sizeof(strs) / sizeof(strs[0]);

    char *prefix = LCP(strs, 0, n - 1);
    printf("Prefix: %s\n", prefix);

    free(prefix);
    return 0;
}
