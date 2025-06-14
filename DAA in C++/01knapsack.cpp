/*
Let n be the number of items.

Let W be the maximum weight (capacity) of the knapsack.

The time complexity of the dynamic programming solution is:

𝑂(𝑛⋅𝑊)

The space complexity of the dynamic programming solution is:

𝑂(𝑛⋅𝑊)
​
This is because it fills out a 2D table of size n x W, where each entry represents the solution to a subproblem (i.e., the maximum value for the first i items and capacity j).
*/
#include <iostream>
using namespace std;

struct Item {
    int value;
    int weight;
};

// 0/1 Knapsack using Dynamic Programming
int zeroOneKnapsack(int size, Item items[], int capacity) {
    int dp[size + 1][capacity + 1];

    for (int i = 0; i <= size; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
            {
                dp[i][w] = 0;
            }    
            else if (items[i - 1].weight <= w)
            {
                dp[i][w] = max(items[i - 1].value + dp[i - 1][w - items[i - 1].weight],dp[i - 1][w]);
            }                   
            else
            {
                dp[i][w] = dp[i - 1][w];
            }  
            
              cout<<dp[i][w]<<" ";
        }
        cout<<endl;
    }

    return dp[size][capacity];
}

int main() {
    int size = 3;
    Item items[size] = {
        {4, 1},
        {5, 2},
        {6, 3}
    };

    int capacity = 4;

    cout << "Maximum Value: " << zeroOneKnapsack(size, items, capacity) << endl;
    return 0;
}

/*
Practical Applications
1.Resource Allocation

       Selecting a subset of projects or tasks to fund under a limited budget.

       Maximizing profit while staying within constraints (e.g., CPU, memory, or energy limits).

2.Cargo Loading / Logistics

       Choosing which items to load onto a truck, ship, or plane to maximize value without exceeding weight or volume constraints.

3.Investment Decisions

       Picking a portfolio of assets or projects where each has a cost and expected return, but the total investment is limited.

4.Memory or Storage Management

       Selecting files or processes to load into limited memory to maximize utility or minimize runtime.

5.Subset Selection in Machine Learning

       Feature selection where each feature has a "cost" and "value," and you want to pick the most informative features under a constraint.
*/
