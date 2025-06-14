/*
Time Complexity
       T(n) = 2T(n/2) + 2

       The array is split into two halves recursively (like Merge Sort).

       At each level, two comparisons are made to combine the min and max from each half.

       Solving the recurrence:
       → T(n) = O(n)

       Time Complexity: O(n)
       Because each element is compared at most once (or very few times), it's efficient — better than the naive 2n - 2 comparisons in the        brute-force method.

Space Complexity
       Auxiliary space is used for recursive calls on the stack.

       The depth of the recursion tree is log n.

       Space Complexity: O(log n) (due to recursion stack)
*/
#include <iostream>
using namespace std;

struct MinMax
{
    int min;
    int max;
};

MinMax minMax(int arr[], int low, int high)
{
    MinMax result, left, right;
    if (low == high)
    {
        result.min = arr[low];
        result.max = arr[high];
    }
    else if (low == high - 1)
    {

        if (arr[low] < arr[high])
        {
            result.min = arr[low];
            result.max = arr[high];
        }
        else
        {
            result.max = arr[low];
            result.min = arr[high];
        }
    }
    else
    {
        int mid = (low + high) / 2;

        left = minMax(arr, low, mid);
        right = minMax(arr, mid + 1, high);

        if (left.max > right.max)
        { 
            result.max = left.max;
        }
        else
        {
            result.max = right.max;
        }

        if (left.min < right.min)
        {
            result.min = left.min;
        }
        else
        {
            result.min = right.min;
        }
    }
    return result;
}

int main()
{
    int arr[] = {8, 3, 5, 6, 9, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    MinMax output = minMax(arr, 0, n - 1);

    cout << "Maximum value : " << output.max << endl;
    cout << "Minimum value : " << output.min << endl;

    return 0;
}