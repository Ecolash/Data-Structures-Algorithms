#include <iostream>

// Function to set the kth bit of n
int setBit(int n, int k)
{
    return (n | (1 << (k - 1)));
}

// Function to clear the kth bit of n
int clearBit(int n, int k)
{
    return (n & (~(1 << (k - 1))));
}

// Function to toggle the kth bit of n
int toggleBit(int n, int k)
{
    return (n ^ (1 << (k - 1)));
}

int main()
{
    int n = 5, k = 1;

    std::cout << n << " with " << k << "-th bit Set: " << setBit(n, k) << std::endl;
    std::cout << n << " with " << k << "-th bit Cleared: " << clearBit(n, k) << std::endl;
    std::cout << n << " with " << k << "-th bit Toggled: " << toggleBit(n, k) << std::endl;

    return 0;
}
