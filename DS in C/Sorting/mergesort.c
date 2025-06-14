#include <stdio.h>

/*
Function Merge(arr[], left, mid, right)
    // Create a temporary array to hold merged values
    temp[right - left + 1] // Temporary array

    i = left             // Starting index of left subarray
    j = mid + 1         // Starting index of right subarray
    k = left             // Starting index for temp array

    // Merge elements into temp array
    While i <= mid and j <= right
        If arr[i] <= arr[j]
            temp[k] = arr[i]
            Increment i
        Else
            temp[k] = arr[j]
            Increment j
        End If
        Increment k
    End While

    // Copy remaining elements from left subarray
    While i <= mid
        temp[k] = arr[i]
        Increment i
        Increment k
    End While

    // Copy remaining elements from right subarray
    While j <= right
        temp[k] = arr[j]
        Increment j
        Increment k
    End While

    // Copy temp array back to original array
    For i from left to right
        arr[i] = temp[i]
    End For
End Function

Function MergeSort(arr[], left, right)
    If left < right
        mid = left + (right - left) / 2    // Calculate the midpoint

        // Recursively sort the two halves
        Call MergeSort(arr, left, mid)       // Sort the left half
        Call MergeSort(arr, mid + 1, right)  // Sort the right half

        // Merge the sorted halves
        Call Merge(arr, left, mid, right)    // Merge the two sorted halves
    End If
End Function

Complexity Analysis of Merge Sort:
Time Complexity:
Best Case: O(n log n), When the array is already sorted or nearly sorted.
Average Case: O(n log n), When the array is randomly ordered.
Worst Case: O(n log n), When the array is sorted in reverse order.

Auxiliary Space: O(n), Additional space is required for the temporary array used during merging.
*/
void merge(int arr[], int left, int mid, int right)
{
    int temp[right - left + 1]; // Temporary array
    int i = left;               // Starting index of left subarray
    int j = mid + 1;            // Starting index of right subarray
    int k = left;               // Index for temp array

    // Merge elements into temp array
    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements from left subarray
    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    // Copy remaining elements from right subarray
    while (j <= right)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    // Copy temp array back to original array
    for (i = left; i <= right; i++)
    {
        arr[i] = temp[i];
    }
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        // Recursively sort the two halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7,2};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, size);

    mergeSort(arr, 0, size - 1);

    printf("Sorted array:\n");
    printArray(arr, size);

    return 0;
}
