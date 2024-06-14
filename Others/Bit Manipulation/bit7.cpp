// BITSET

// A bitset is an array of bools but each boolean value is not stored in a separate byte
// Bitset optimizes the space such that each boolean value takes 1-bit space only, so space taken by bitset is less than that of an array of bool or vector of bool.
// A limitation of the bitset is that size must be known at compile time i.e.size of the bitset is fixed.
// C++ program to demonstrate the bitset

#include <bitset>
#include <iostream>

using namespace std;

int main()
{
    bitset<8> U;
    bitset<8> D(13);
    bitset<8> S(string("1111"));

    cout << "Uninitialized bitset: " << U << endl;
    cout << "Initialized with decimal: " << D << endl;
    cout << "Initialized with string: " << S << endl;

    cout << "Size of Uninitialized bitset: " << sizeof(U) << endl;
    cout << "Size of Initialized with decimal: " << sizeof(D) << endl;
    cout << "Size of Initialized with string: " << sizeof(S) << endl;
    cout << "Size of Initialized with string: " << sizeof(int) * 8 << endl;

    return 0;
}
