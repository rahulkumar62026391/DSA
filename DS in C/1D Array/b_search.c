#include <stdio.h>

int binarySearch(int array[], int low, int high, int num)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (array[mid] == num)
            return mid;
        if (num < array[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}
int main()
{
    int size,num;
    printf("Enter the size of array :");
    scanf("%d", &size);
    int array[size];
    printf("Please,Enter the element in ascending order \n");
    for (int i = 0; i < size; i++)
    {
        printf("Enter the element at index %d :", i);
        scanf("%d", &array[i]);
    }
    printf("Enter the element that you want to search :");
    scanf("%d",&num);
    int result=binarySearch(array,0, size-1, num);
    if(result==-1){
        printf("Required element is not found");
    }else{
        printf("Required element is found at index : %d",result);
    }
    

    return 0;
}