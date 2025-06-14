#include<iostream>
using namespace std;

void selectionSort(int arr[],int size)
{
    for(int i=0;i<size-1;i++)
    {
        int min_index=i;
        for(int j=i+1;j<size;j++)
        {
            if(arr[j]<arr[min_index])
            {
                min_index=j;
            }

        }

        if(min_index!=i)
        {
            int temp=arr[i];
            arr[i]=arr[min_index];
            arr[min_index]=temp;
        }
    }


}

void print(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int arr[]={5,8,1,3,7};
    int size=sizeof(arr)/sizeof(arr[0]);

    print(arr,size);

    selectionSort(arr,size);
    
    print(arr,size);

    return 0;
}