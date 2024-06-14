#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getMax(vector<string> arr)
{
    int max = arr[0].size();
    for (int i = 1; i < arr.size(); ++i)
    {
        if (arr[i].size() > max)
            max = arr[i].size();
    }
    return max;
}

void countingSort(vector<string> &arr, int pos)
{
    const int ALPHABET_SIZE = 26;
    vector<string> output(arr.size());
    vector<int> count(ALPHABET_SIZE, 0);

    for (size_t i = 0; i < arr.size(); ++i)
        count[arr[i].size() < pos ? 0 : arr[i][arr[i].size() - pos] - 'a' + 1]++;

    for (int i = 1; i < ALPHABET_SIZE; ++i)
        count[i] = count[i] + count[i - 1];

    for (int i = arr.size() - 1; i >= 0; --i)
    {
        output[count[arr[i].size() < pos ? 0 : arr[i][arr[i].size() - pos] - 'a' + 1] - 1] = arr[i];
        count[arr[i].size() < pos ? 0 : arr[i][arr[i].size() - pos] - 'a' + 1]--;
    }

    for (size_t i = 0; i < arr.size(); ++i)
        arr[i] = output[i];
}

void printArray(const vector<string> &arr)
{
    for (const auto &str : arr)
        cout << str << " | ";
    cout << endl;
}

void radixSort(vector<string> &arr)
{
    int max = getMax(arr);
    cout << "-------------------------------------------------------------------------------------------------" << endl;
    for (int pos = 1; pos <= max; pos++)
    {
        countingSort(arr, pos);
        cout << "Pass " << pos << ": ";
        printArray(arr);
    }
    cout << "-------------------------------------------------------------------------------------------------" << endl;
}

int main()
{
    vector<string> arr = {"apple", "pears", "mango", "berry", "grape"};
    cout << "Before sorting: ";
    printArray(arr);

    radixSort(arr);

    cout << "After sorting: ";
    printArray(arr);

    return 0;
}
