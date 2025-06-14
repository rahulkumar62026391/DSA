/*
Time Complexity:
     Sorting the items by their value-to-weight ratio:

     Sorting is the most computationally expensive operation here.

     If there are n items, the sorting operation takes O(n log n) time using a comparison-based sort (like quicksort or mergesort).

     Processing the items to fill the knapsack:

     This requires a single pass through the sorted items, which takes O(n) time.

     Thus, the overall time complexity is dominated by the sorting step:

     Time Complexity: O(n log n)

Space Complexity:

     Storing the items:

     We need space to store the items, which requires O(n) space, where n is the number of items.

     Other auxiliary space:

     The sorting operation typically requires O(log n) auxiliary space (if using an efficient in-place sorting algorithm like quicksort), 
but      this is negligible compared to the space for storing the items.

     Thus, the overall space complexity is:

     Space Complexity: O(n)

Conclusion:
Time Complexity: O(n log n)

Space Complexity: O(n)
*/

#include<iostream>
using namespace std;

struct Item
{
    int value;
    int weight;
    double ratio;
};

void bubbleSort(Item items[],int size)
{
    bool swapped;

    for(int i=0;i<size-1;i++)
    {
        swapped=false;

        for(int j=0;j<size-1-i;j++)
        {
            if(items[j].ratio < items[j+1].ratio)
              {
                Item temp=items[j];
                items[j]=items[j+1];
                items[j+1]=temp;

                swapped=true;
              }
        }

        if(swapped==false)
              break;
    }
    for(int i=0;i<size;i++)
    {
      cout<<items[i].value<<" "<<items[i].weight<<" "<<items[i].ratio<<endl;
    }
}

double fracknapsack(int size,Item items[],int capacity)
{
   for(int i=0;i<size;i++)
   {
    items[i].ratio=(double)(items[i].value/items[i].weight);
   }

   bubbleSort(items,size);

   double totalvalue=0.0;
   int currentweight=0;

   for(int i=0;i<size;i++)
   {
    if(currentweight + items[i].weight<= capacity)
     {
        currentweight+=items[i].weight;
        totalvalue+=items[i].value;
     }else{
        int remainingcapacity=capacity-currentweight;
        totalvalue+=items[i].ratio * remainingcapacity;
     }
   }
 return totalvalue;

}

int main()
{
    int size=3;
    Item items[size]={
                    {100,20,0.0},
                    {60,10,0.0},
                    {120,30,0.0}
                };

    int capacity=50;

    cout<<"Maximum Value : "<<fracknapsack(size,items,capacity)<<endl;
    return 0;
}