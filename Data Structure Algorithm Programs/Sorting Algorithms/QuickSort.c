#include <stdio.h>


void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


int partition(int arr[], int low, int high)
/*
Function to find partition position
*/
{
    // Select rightmost element as pivot
    int pivot = arr[high];

    // Pointer for greater element
    int i = low - 1;

    /*
    Traverse each element of the array and
    compare them with the pivot
    */
    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            /*
            If element smaller than pivot is found then
            swap it with greater element pointed by "i"
            */
            i++;

            // Swap element at i with element at j
            swap(&arr[i], &arr[j]);
        }
    }

    // Swap pivot element with greater element at i
    swap(&arr[i + 1], &arr[high]);

    // Return partition point
    return (i + 1);
}


void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /*
        Find pivot element such that elements smaller than
        pivot are left of pivot and elements greater than
        pivot are on right of pivot.
        */

        int pi = partition(arr, low, high);

        // Recursive call on left of pivot
        quickSort(arr, low, pi - 1);

        // Recursive call on right of pivot
        quickSort(arr, pi + 1, high);
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

    quickSort(arr, 0, size);
    printArray(arr, size);

    return 0;
}