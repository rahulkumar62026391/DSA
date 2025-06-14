/*
Time Complexity
       Case	Time	Explanation
       Best	O(n log n)	Always splits the array in half and merges in linear time
       Average	O(n log n)	Works the same regardless of input ordering
       Worst	O(n log n)	Merge sort doesn't degrade like quicksort on bad input — very predictable

       Why O(n log n)?

       Divide: Array is recursively divided into halves → log n levels

       Conquer: At each level, merging takes O(n) time

       Total: O(n log n)

Space Complexity
       O(n) extra space

       Why?

       Merge Sort needs a temporary array to merge sorted halves, which requires additional space proportional to the input size.
*/
#include<iostream>
using namespace std;

void merge(int arr[],int low,int mid,int high){
        //int n=sizeof(arr)/sizeof(arr[0]);

        int temp[high-low+1];

        int i=low;
        int j=mid+1;

        int k=low;

        while(i<=mid && j<=high){
            if(arr[i]<=arr[j]){
                temp[k]=arr[i];
                    i++;
            }else{
                temp[k]=arr[j];
                    j++;
            }
                    k++;
        }

        while(i<=mid){
            temp[k]=arr[i];
                i++;
                k++;
        }

        while(j<=high){
            temp[k]=arr[j];
                k++;
                j++;
        }

        for(int l=low;l<=high;l++){
            arr[l]=temp[l];
        }
}

void mergeSort(int arr[],int low,int high){

    if(low<high){

    int mid=low+(high-low)/2;

    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);

    merge(arr,low,mid,high);

    }       
}

void printArray(int arr[],int size){
   // int n=sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
        int arr[]={5,2,9,3,4};

        int n=sizeof(arr)/sizeof(arr[0]);

        cout<<"Unsorted Array :"<<endl;
        printArray(arr,n);

        mergeSort(arr,0,n-1);

        cout<<"Sorted Array :"<<endl;
        printArray(arr,n);
    return 0;
}