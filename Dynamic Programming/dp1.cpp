// FIBONACCI SEQUENCE
// MEMORIZATION

#include <iostream>
using namespace std;

/*

NOTE: Recursive solutuion requires more time for larger number

Time complexity : O(2^n)
Space complexity : O(n)

int fibonacciRecursive(int n)
{
    if (n <= 1)
        return n;

    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

*/
//-----------------------------------------------------------------------------------
/*

NOTE: DP requires less time for larger number

Time complexity : O(n)
Space complexity : O(n)

*/

int fibonacciDP(int n)
{
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    // cout << "Fibonacci number at position " << n << " (using recursion) is: ";
    // cout << fibonacciRecursive(n) << endl;

    cout << "Fibonacci number at position " << n << " (using dynamic programming) is: ";
    cout << fibonacciDP(n) << endl;

    return 0;
}
