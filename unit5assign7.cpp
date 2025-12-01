#include <iostream>
using namespace std;

#define MAX 20
#define INF 9999  // infinity value for no direct connection

int main() {
    int V; // number of vertices
    int graph[MAX][MAX];
    int source, dest;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter adjacency matrix (0 if no edge):\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 0 && i != j)
                graph[i][j] = INF; // no direct edge
        }
    }

    cout << "Enter source vertex (0 to " << V - 1 << "): ";
    cin >> source;
    cout << "Enter destination vertex (0 to " << V - 1 << "): ";
    cin >> dest;

    int dist[MAX];   // distance from source
    bool visited[MAX]; // visited vertices

    // Step 1: Initialize distances
    for (int i = 0; i < V; i++) {
        dist[i] = graph[source][i];
        visited[i] = false;
    }
    dist[source] = 0;
    visited[source] = true;

    // Step 2: Find shortest path for all vertices
    for (int count = 1; count < V - 1; count++) {
        int minDist = INF, u = -1;

        // find vertex with minimum distance
        for (int i = 0; i < V; i++) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }

        visited[u] = true;

        // update distances of neighbors
        for (int v = 0; v < V; v++) {
            if (!visited[v] && (dist[u] + graph[u][v] < dist[v])) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    cout << "\nShortest distance from " << source << " to " << dest << " is: " << dist[dest] << endl;

    cout << "\nVertex\tDistance from Source\n";
    for (int i = 0; i < V; i++) {
        if (dist[i] != INF)
            cout << i << "\t" << dist[i] << endl;
        else
            cout << i << "\tINF\n";
    }

    return 0;
}
