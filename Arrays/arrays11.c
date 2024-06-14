// REVERSE OF ARRAY USING FUNCTION

#include <stdio.h>

void reverse(int array[], int n);
int main()
{
    int n;
    printf("Enter no. of elements : ");
    scanf("%d", &n);

    int array[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter n(%d) : ", i + 1);
        scanf("%d", &array[i]);
    }

    printf("\n");
    reverse(array, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", array[i]); // \t gives a space of TAB
    }
    return 0;
}

void reverse(int array[], int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        int from_first = array[i];
        int from_last = array[n - 1 - i];
        array[i] = from_last;
        array[n - 1 - i] = from_first;
    }
}
