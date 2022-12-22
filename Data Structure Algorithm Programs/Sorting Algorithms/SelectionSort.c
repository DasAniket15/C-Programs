#include <stdio.h>


void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


void SelectionSort(int  arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min = i;

        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }

        swap(&arr[min], &arr[i]);
    }
}


void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}


int main()
{
    int arr[] = {5, 2, 3, 1, 6, 4};

    int size = sizeof(arr) / sizeof(arr[0]);

    SelectionSort(arr, size);
    printArray(arr, size);

    return 0;
}