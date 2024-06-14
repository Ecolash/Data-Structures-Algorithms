#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a = 5; // binary: 0101
    int b = 3; // binary: 0011

    int c1 = a & b;
    int c2 = a | b;
    int c3 = a ^ b;
    int c4 = ~a;
    int c5 = a << 1;
    int c6 = a >> 1;

    cout << "Bitwise AND: " << c1 << endl;
    cout << "Bitwise OR: " << c2 << endl;
    cout << "Bitwise XOR: " << c3 << endl;
    cout << "Bitwise NOT (on 'a'): " << c4 << endl;
    cout << "Left shift by 1: " << c5 << endl;
    cout << "Right shift by 1: " << c6 << endl;

    return 0;
}
