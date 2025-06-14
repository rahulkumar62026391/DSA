#include <iostream>
using namespace std;

int partition(int arr[], int low, int high)
{

    int pivot = arr[low];

    int left = low + 1;
    int right = high;

    while (left <= right)
    {

        while (arr[left] <= pivot && left<=right)
        {
            left++;
        }

        while (arr[right] > pivot && left<=right)
        {
            right--;
        }

        if (left < right)
        {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
        }
    }
    int temp = arr[right];
    arr[right] = arr[low];
    arr[low] = temp;

    return right;
}

void quickSort(int arr[], int low, int high)
{

    if (low < high)
    {
        int pivot = partition(arr, low, high);

        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

void printArray(int arr[], int size)
{

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout<<endl;
}

int main()
{

    int arr[] = {8,7,6,5,4,3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printArray(arr,n);

    quickSort(arr, 0, n - 1);

    printArray(arr, n);

    return 0;
}