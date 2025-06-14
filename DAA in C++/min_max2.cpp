#include<iostream>
using namespace std;

struct MaxMin{
   int max;
   int min;
};

MaxMin minMax(int arr[],int size){
    int min,max=arr[0];

    MaxMin result;

    for(int i=1;i<size;i++){
        if(arr[i]>max)
         max=arr[i];
    }

   for(int j=1;j<size;j++){
        if(arr[j]<min)
        min=arr[j];
    }

    result.max=max;
    result.min=min;

    return result;
}

int main(){

    int arr[]={2,6,1,8,3};
    int size=sizeof(arr)/sizeof(arr[0]);

    MaxMin output=minMax(arr,size);

    cout<<"Max = "<<output.max<<" Min = "<<output.min<<endl;
    return 0;
}