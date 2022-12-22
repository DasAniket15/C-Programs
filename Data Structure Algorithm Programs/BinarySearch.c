#include <stdio.h>


// Function to search for element within sorted array
int binarySearch(int A[], int s, int data)
{
    int mid, first = 0, last = s - 1;
    
    // While loop which runs until first index is less than or equal to last index of array
    while (first <= last)
    {
        // Finding middle index of array
        mid = (first + last) / 2;

        /*
        Comparing element to be searched with middle element of array.
        
        If it is greater, then array is halved and the first half is removed by making
        first index equal to middle index.

        If it is less, then array is halved and the second half is removed by making last
        index equal to middle index.

        At the end of the while loop, the desired element should be the only element left
        after halving the array again and again, so return the middle index element.

        If the element is not present at all in the array, then just return -1.
        */
        if (data > A[mid])
        {
            first = mid;
        }

        else if (data < A[mid])
        {

            last = mid;
        }

        else
        {
            return mid;
        }
    }

    return  -1;
}


int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    int val, found;

    printf("Enter the number you want to search : ");
    scanf("%d", &val);

    found = binarySearch(arr, size, val);

    if (found == -1)
    {
        printf("\nItem not found");
    }

    else
    {
        printf("\nItem found at index %d", found);
    }

    return 0;
}