/*
Complexity Analysis
   Time Complexity: O(m^V)

         V: number of vertices
         m: number of colors

         Every vertex has up to m choices → exponential growth

   Space Complexity: O(V)

         For the color[] array and recursion stack
*/

#include <iostream>
using namespace std;

#define V 4 // Number of vertices

bool isSafe(int v, bool graph[V][V], int color[], int c) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && color[i] == c)
            return false;
    }
    return true;
}

bool graphColoringUtil(bool graph[V][V], int m, int color[], int v) {
    if (v == V)
        return true;

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c;

            if (graphColoringUtil(graph, m, color, v + 1))
                return true;

            color[v] = 0; // Backtrack
        }
    }

    return false;
}

int findChromaticNumber(bool graph[V][V]) {
    int color[V];
    for (int m = 1; m <= V; m++) {
        for (int i = 0; i < V; i++) color[i] = 0;

        if (graphColoringUtil(graph, m, color, 0)) {
            // Output the coloring
            cout << "Minimum colors needed: " << m << endl;
            for (int i = 0; i < V; i++) {
                cout << "Vertex " << i << " --> Color " << color[i] << endl;
            }
            return m;
        }
    }
    return V;
}

int main() {
    bool graph[V][V] = {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0}
    };

    findChromaticNumber(graph);

    return 0;
}
