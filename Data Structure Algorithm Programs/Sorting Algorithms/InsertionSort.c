#include <stdio.h>


void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (key < arr[j] && j >= 0)
        {
            arr[j + 1] = arr[j];
            
            j--;
        }

        arr[j + 1] = key;
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

    insertionSort(arr, size);
    printArray(arr, size);

    return 0;
}