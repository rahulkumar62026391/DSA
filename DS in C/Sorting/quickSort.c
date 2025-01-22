#include <stdio.h>

/*
FUNCTION PARTITION(A[], low, high)
    pivot = A[low]           // Choose the first element as the pivot
    left = low + 1           // Left pointer starts after the pivot
    right = high             // Right pointer starts at the end

    // Continue until the pointers cross
    WHILE left <= right 
        // Move the left pointer to the right while elements <= pivot
        WHILE left <= right AND A[left] <= pivot
            left = left + 1
        END WHILE

        // Move the right pointer to the left while elements > pivot
        WHILE left <= right AND A[right] > pivot 
            right = right - 1
        END WHILE

        // If the pointers have not crossed, swap the elements
        IF left < right THEN
            temp = A[left]
            A[left] = A[right]
            A[right] = temp
        END IF
    END WHILE

    // Place the pivot in its correct position
    temp = A[low]
    A[low] = A[right]
    A[right] = temp

    // Return the index of the pivot's new position
    RETURN right
END FUNCTION


FUNCTION QUICKSORT(A[], low, high)
    IF low < high THEN
        // Partition the array and get the pivot index
        pivot = PARTITION(A, low, high)
        
        // Recursively sort the left sub-array (before the pivot)
        QUICKSORT(A, low, pivot - 1)
        
        // Recursively sort the right sub-array (after the pivot)
        QUICKSORT(A, pivot + 1, high)
    END IF
END FUNCTION

*/

/*
// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

Time and Space Complexity Analysis of Quick Sort
The time complexity of Quick Sort is O(n log n) on average case, but can become O(n^2) in the worst-case. 
The space complexity of Quick Sort in the best case is O(log n), while in the worst-case scenario, it becomes O(n) due to unbalanced partitioning causing a skewed recursion tree that requires a call stack of size O(n).
*/

// Partition function using the first element as pivot
int partition(int arr[], int low, int high)
{
    int pivot = arr[low]; // Pivot is the first element
    int left = low + 1;   // Start from the second element
    int right = high;

    while (left <= right)
    {
        // Move the left pointer until a larger element is found
        while (left <= right && arr[left] <= pivot)
            left++;
        // Move the right pointer until a smaller element is found
        while (left <= right && arr[right] > pivot)
            right--;

        // Swap left and right elements if they are in the wrong place
        if (left < right)
        {

            // swap(&arr[left], &arr[right]);

            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
        }
    }

    // Swap the pivot with the right pointer

    // swap(&arr[low], &arr[right]);

    int temp = arr[low];
    arr[low] = arr[right];
    arr[right] = temp;

    // Return the final position of the pivot
    return right;
}

// Quicksort function
void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high); // Partition the array

        // Recursively sort the left and right sub-arrays
        quicksort(arr, low, pivot - 1);
        quicksort(arr, pivot + 1, high);
    }
}

// Function to print an array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main()
{
    int arr[] = {15, 3, 2, 10, 6, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    quicksort(arr, 0, n - 1);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}
