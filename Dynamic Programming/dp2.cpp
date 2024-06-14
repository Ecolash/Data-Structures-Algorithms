// FIBONACCI SEQUENCE
// SPACE OPTIMIZATION

#include <iostream>
using namespace std;

int fibonacciDP(int n)
{
    // NOTE : Instead of using array we just use 3 variables

    // Time complexity : O(n)
    // Space complexity : O(1)

    int prev1 = 1;
    int prev2 = 0;

    for (int i = 2; i <= n; i++)
    {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    cout << "Fibonacci number at position " << n << " (using dynamic programming) is: ";
    cout << fibonacciDP(n) << endl;

    return 0;
}
