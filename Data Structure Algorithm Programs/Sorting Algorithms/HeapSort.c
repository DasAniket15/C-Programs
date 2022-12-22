#include <stdio.h>


void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


void heapify(int arr[], int size, int i)
{
    // Find largest among root, left child, and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[left] > arr[largest])
    {
        largest = left;
    }

    if (right < size && arr[right] > arr[largest])
    {
        largest = right;
    }

    // Swap and continue heapifying if root is not largest
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, size, largest);
    }
}


void heapSort(int arr[], int size)
{
    // Build max heap
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(arr, size, i);
    }

    // Heap sort
    for (int i = size - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);

        // Heapify root element to get highest element at root again
        heapify(arr, i, 0);
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

    heapSort(arr, size);
    printArray(arr, size);

    return 0;
}