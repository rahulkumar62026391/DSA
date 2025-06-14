#include <iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int num)
{
    if (low <= high)
    {

        int mid =low+(high-low) / 2;

        if (arr[mid] == num)
            return mid;
        if (num < arr[mid])
        {
           return  binarySearch(arr, low, mid - 1, num);
        }
        else
        {
           return  binarySearch(arr, mid + 1, high, num);
        }
    }
    return -1;
}

// int binarySearch(int arr[],int low,int high,int num){
//     while(low<=high){

//         int mid=low +(high-low)/2;

//             if(arr[mid]==num)
//             return mid;

//             if(num< arr[mid]){
//                 high=mid-1;
//             }else{
//                 low=mid+1;
//             }
//     }

//       return -1;
// } 


int main()
{

    int arr[] = {1, 2, 3, 4, 5, 6};
    int num = 6;

    int x = binarySearch(arr, 0, 5, num);

    if (x == -1)
    {
        cout << num << " is not found.";
    }
    else
    {
        cout << num << " is found at " << x <<".";
    }
    return 0;
}