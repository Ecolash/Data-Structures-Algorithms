// NUMBER OF INVERSIONS IN AN ARRAY
// INVERSION PAIR (i , j) : i < j and A[i] > A[j]

#include <iostream>
using namespace std;

int inversions;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// STEP - 2 : MERGE SUB ARRAYS INTO A SORTED ARRAY

void countInversions(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }

    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1 + j];
    }

    // NOTE: i ,j, k stores location of index of arrays L, R and arr

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }

        else if (L[i] > R[j])
        {
            arr[k] = R[j];
            inversions = inversions + (n1 - i);
            j++;
        }

        k++;
    }

    // NOTE : Sorting the remaining values

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        countInversions(arr, l, m, r);
    }
}

int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    inversions = 0;

    cout << "Original array: ";
    printArray(arr, size);

    mergeSort(arr, 0, size - 1);

    cout << "Number of Inversions: " << inversions << endl;
    printArray(arr, size);

    return 0;
}
