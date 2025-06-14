#include <iostream>
using namespace std;

// Job structure
struct Job {
    char id;
    int deadline;
    int profit;
};

//bubble sort by profit (descending)
void sortJobsByProfit(Job jobs[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (jobs[j].profit < jobs[j + 1].profit) {
                Job temp = jobs[j];
                jobs[j] = jobs[j + 1];
                jobs[j + 1] = temp;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<jobs[i].id<<" "<<jobs[i].deadline<<" "<<jobs[i].profit<<endl;
    }
}

void jobSequencing(Job jobs[], int n) {
    // Sort jobs by profit
    sortJobsByProfit(jobs,n);

    // Find max deadline to size the time slots
    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
        if (jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;

    // Time slots: -1 means empty
    int slot[maxDeadline];
    for (int i = 0; i < maxDeadline; i++)
        slot[i] = -1;

    int totalProfit = 0;

    cout << "Scheduled Jobs: ";
    for (int i = 0; i < n; i++) {
        // Find a free slot for this job (from deadline - 1 to 0)
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (slot[j] == -1) {
                slot[j] = i; // Assign job index to slot
                totalProfit += jobs[i].profit;
                cout << jobs[i].id << " ";
                break;
            }
        }
    }

    cout << "\nTotal Profit: " << totalProfit << endl;
}

int main() {
    Job jobs[] = {
        {'A', 2, 100},
        {'B', 1, 19},
        {'C', 2, 27},
        {'D', 1, 25},
        {'E', 3, 15}
    };
    int n = sizeof(jobs) / sizeof(jobs[0]);

    jobSequencing(jobs, n);

    return 0;
}
