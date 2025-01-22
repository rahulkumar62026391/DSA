/* Concept :
 You split the array into two groups: the sorted group and the unsorted group.
Then, you pick an element from the unsorted group and put it in the right place in the sorted group.
*/

/*
Function InsertionSort(arr[], size)
    For i from 1 to size - 1     // (int i = 1; i < size; i++)
        key = arr[i]
        j = i - 1
        
        While j >= 0 and arr[j] > key
            arr[j + 1] = arr[j]
            j = j - 1
        End While
        
        arr[j + 1] = key
    End For
End Function

Complexity Analysis of Insertion Sort :
Time Complexity of Insertion Sort
Best case: O(n) , If the list is already sorted, where n is the number of elements in the list.
Average case: O(n 2 ) , If the list is randomly ordered
Worst case: O(n 2 ) , If the list is in reverse order

Space Complexity of Insertion Sort
Auxiliary Space: O(1), Insertion sort requires O(1) additional space, making it a space-efficient sorting algorithm.
*/

#include <stdio.h>

void insertionSort(int arr[], int size);
void print(int arr[], int size);

int main()
{
    int arr[] = {4, 1, 6, 9, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    // call print function
    printf("Array before insertion sort:\n");
    print(arr, size);

    // call insertion sort function
    insertionSort(arr, size);

    // call print function
    printf("Array after insertion sort:\n");
    print(arr, size);

    return 0;
}

// Function to do insertion Sort
void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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