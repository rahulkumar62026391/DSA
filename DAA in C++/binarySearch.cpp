// Binary Search Time Complexity Summary
// Case	Time Complexity
// Best Case	
// O(1)
// Average Case	
// O(logn)
// Worst Case	
// O(logn)
// This applies to both successful and unsuccessful searches, since binary search always works by halving the search space regardless  
// of the result.
#include<iostream>
using namespace std;

int binarySearch(int arr[],int low,int high,int num)
{ 
    if(low<=high)
    {
       int mid=low+(high-low)/2;
       if(arr[mid]==num)
         return mid;

         if(num<arr[mid])
         {
             return binarySearch(arr,low,mid,num);
         }else{
             return binarySearch(arr,mid+1,high,num);
         }
    }
    return -1;
}

int main()
{
    int arr[5]={2,5,7,8,9};
    int index=binarySearch(arr,0,4,2);
    if(index!=-1)
    {
        cout<<"Element is found at index "<<index<<endl;
    }else{
        cout<<"Element is not found."<<endl;
    }

    return 0;

}