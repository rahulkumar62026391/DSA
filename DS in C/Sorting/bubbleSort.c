/* Concept :
Compare adjacent elements: Starting from the first element, compare each element with the next.

Swap if needed: If the current element is greater than the next element, swap them.

Bubble up largest element: After the first pass, the largest element will have "bubbled up" to the
last position.

Repeat for remaining unsorted portion: Ignore the last sorted element and repeat the process for
the remaining unsorted portion of the list.

Stop when no swaps are needed: If a full pass is made without any swaps, the list is sorted, and
 the algorithm stops.
 */

/*
BubbleSort(arr[], size)
    For i from 0 to size - 2     // Using (int i = 0; i < size - 1; i++)
        Set swapped = false      // Using  #include<stdbool.h>
        
        For j from 0 to size - i - 2  // Using (int j = 0; j < size - i - 1; j++)
            If arr[j] > arr[j + 1]

                temp = arr[j]
                arr[j] = arr[j + 1]
                arr[j + 1] = temp
                Set swapped = true

            End If
        End For
        
        If swapped is false
            Exit the loop early  // break
            
        End If
    End For
End Function

The bubble sort algorithm
Average/worst time complexity is O(n²).
Space complexity is O(1).
*/

#include <stdio.h>
#include <stdbool.h>

void bubbleSort(int arr[], int size);
// void swap(int *ptr1, int *ptr2);
void print(int arr[], int size);

int main()
{

    int arr[] = {5, 1, 8, 3, 6, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Print array after bubble sort
    printf("Array before bubble sort\n");
    print(arr, size);

    // Call bubble sort function
    bubbleSort(arr, size);

    // Print array after bubble sort
    printf("Array after bubble sort\n");
    print(arr, size);

    return 0;
}
// Function to do bubble sort
void bubbleSort(int arr[], int size)
{
    bool swapped;
    for (int i = 0; i < size - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // swap(&arr[j], &arr[j + 1]);

                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}
/*
// Function to do swap
void swap(int *ptr1, int *ptr2)
{
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}
*/

// Function to print array
void print(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}