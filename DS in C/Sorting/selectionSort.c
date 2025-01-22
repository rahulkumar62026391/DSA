/*  Concept:
The algorithm divides the list into two parts:

Sorted portion: At the beginning of the list, which initially contains only the first element.

Unsorted portion: The rest of the list, which is unsorted.

The algorithm repeatedly selects the smallest (or largest) element from the unsorted portion and
swaps it with the first element in the unsorted portion, effectively expanding the sorted portion
of the list.
*/

/*
FUNCTION selectionSort(arr, size)
    For i from 0 to size - 2         //(int i = 0; i < size - 1; i++)
        // Assume the minimum element is at index i
        index = i

        // Find the smallest element in the unsorted portion
        For j from i + 1 to size - 1     //(int j = i + 1; j < size; j++)
            If arr[j] < arr[index] then
                index = j
            End If
        End For

        // Swap the elements if a smaller element is found
        If index != i then
            temp = arr[i]
            arr[i] = arr[index]
            arr[index] = temp
        End If
    End For
End FUNCTION

Time Complexity Analysis of Selection Sort:
Best-case: O(n2), best case occurs when the array is already sorted. (where n is the number of integers in an array)
Average-case: O(n2), the average case arises when the elements of the array are in a disordered or random order, without a clear ascending or descending pattern.
Worst-case: O(n2), The worst-case scenario arises when we need to sort an array in ascending order, but the array is initially in descending order.

Auxiliary Space Complexity Analysis of Selection Sort:
Space Complexity: O(1), as no extra space is required for the Selection sort algorithm

*/

#include <stdio.h>

void selectionSort(int arr[], int size);
void print(int arr[], int size);
int main()
{
    int arr[] = {10, 2, 35, 14, 15};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Print array before sorting
    printf("Array before selection sort:\n");
    print(arr, size);

    // Call selection Sort function
    selectionSort(arr, size);

    // Print array after sorting
    printf("Array after selection sort:\n");
    print(arr, size);

    return 0;
}

// Function to do selection Sort
void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {

        // Assume Index at minimum element is present = index
        int index = i;
        for (int j = i + 1; j < size; j++)
        {
            // Compare the min element to unsorted array
            if (arr[j] < arr[index])
            {
                index = j;
            }
        }
        // swap elements

        if (index != i)
        {
            int temp = arr[i];
            arr[i] = arr[index];
            arr[index] = temp;
        }
    }
}

// Function to print array
void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}