/*
Time Complexity	: O((V + E) log V)
Space Complexity: O(V)
*/

#include <iostream>
#include <climits>  // For INT_MAX
using namespace std;

// Number of vertices in the graph
#define V 4

// Function to find the vertex with minimum distance value
// from the set of vertices not yet included in shortest path tree
int minDistance(int dist[], bool sptSet[]) {
    // Initialize min value
    int min = INT_MAX, min_index=-1;

    for (int v = 0; v < V; v++) {
        if (sptSet[v] == false && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

// Function to print the constructed distance array
void printSolution(int dist[]) {
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << " \t\t" << dist[i] << endl;
}

// Function that implements Dijkstra's algorithm for a graph represented
// using adjacency matrix representation
void dijkstra(int graph[V][V], int src) {
    int dist[V];     // The output array. dist[i] will hold the shortest
                     // distance from src to i

    bool sptSet[V];  // sptSet[i] will be true if vertex i is included in shortest
                     // path tree or shortest distance from src to i is finalized

    // Initialize all distances as INFINITE and sptSet[] as false
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not
        // yet processed. u is always equal to src in the first iteration.
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++) {
            // Update dist[v] only if is not in sptSet, there is an edge from
            // u to v, and total weight of path from src to v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                        dist[v] = dist[u] + graph[u][v];
        }
    }

    // Print the constructed distance array
    printSolution(dist);
}

int main() {
    // Example graph represented as adjacency matrix
    // 0 means no direct edge
    int graph[V][V] = {
        {0, 1, 4, 0},
        {1, 0, 2, 5},
        {4, 2, 0, 1},
        {0, 5, 1, 0}
    };

    // Call dijkstra function with source vertex 0
    dijkstra(graph, 0);

    return 0;
}