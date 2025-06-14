/*
Time complexity : O(n!)
Space Complexity :O(n)
*/

#include <iostream>
#include <climits>
using namespace std;

const int V = 4;
const int INF = INT_MAX;

int tsp(int graph[V][V], bool visited[V], int currPos, int count, int cost, int start) {
    // If all cities are visited, return to starting city
    if (count == V && graph[currPos][start] != 0) {
        return cost + graph[currPos][start];
    }

    int ans = INF;

    // Try next unvisited city
    for (int i = 0; i < V; i++) {
        if (!visited[i] && graph[currPos][i] != 0) {
            visited[i] = true;
            int temp = tsp(graph, visited, i, count + 1, cost + graph[currPos][i], start);
            ans = min(ans, temp);
            visited[i] = false; // backtrack
        }
    }

    return ans;
}

int main() {
    int graph[V][V] = {
        {0, 10, 15,20},
        {5,  0, 9, 10},
        {6, 13, 0, 12},
        {8,  8, 9,  0}
    };

    bool visited[V] = {false};
    visited[0] = true; // start from city 0

    int minCost = tsp(graph, visited, 0, 1, 0, 0);
    cout << "Minimum Cost: " << minCost << endl;

    return 0;
}
