#include <stdio.h>


void merge(int arr[], int p, int q, int r)
/*
Merge two sub-arrays L and M into arr
*/
{
    // Create L <- A[p..q] and M <- A[q+1..r]
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[p + i];
    }

    for (int j = 0; j < n2; j++)
    {
        M[j] = arr[q + 1 + j];
    }

    // Maintaing current index of sub-arrays and arr
    int i, j, k;

    i = 0;
    j = 0;
    k = p;

    /*
    Until we reach either end of either L or M, pick larger among
    elements L and M and place them in the correct position at A[p..r]
    */
    while (i < n1 && j < n2)
    {
        if (L[i] <= M[j])
        {
            arr[k] = L[i];
            i++;
        }

        else
        {
            arr[k] = M[j];
            j++;
        }

        k++;
    }

    /*
    When we run out of elements in either L or M,
    pick up remaining elements and put in A[p..r]
    */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = M[j];
        j++;
        k++;
    }
}


void mergeSort(int arr[], int l, int r)
/*
Divide array into two sub-arrays, sort them and merge them
*/
{
    if (l < r)
    {
        // m is the point where array is divided into two sub-arrays
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the sorted sub-arrays
        merge(arr, l, m, r);
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

    mergeSort(arr, 0 , size);
    printArray(arr, size);

    return 0;
}