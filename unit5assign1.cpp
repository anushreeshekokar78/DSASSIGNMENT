#include <iostream>
#include <queue>
using namespace std;

#define MAX 10  

int adj[MAX][MAX];  
int visited[MAX];  
int n;             

// Function to create adjacency matrix
void createGraph() {
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix (" << n << "x" << n << "):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }
}

// Function to display adjacency matrix
void displayMatrix() {
    cout << "\nAdjacency Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}

// BFS traversal
void BFS(int start) {
    queue<int> q;
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    q.push(start);
    visited[start] = 1;

    cout << "BFS Traversal starting from vertex " << start << ": ";

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " ";

        for (int i = 0; i < n; i++) {
            if (adj[v][i] == 1 && visited[i] == 0) {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
    cout << endl;
}

// DFS traversal (using stack or recursion)
void DFSUtil(int v) {
    visited[v] = 1;
    cout << v << " ";

    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && visited[i] == 0)
            DFSUtil(i);
    }
}

void DFS(int start) {
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    cout << "DFS Traversal starting from vertex " << start << ": ";
    DFSUtil(start);
    cout << endl;
}

// Main function
int main() {
    int choice, start;

    while (true) {
        cout << "\n--- Graph Operations ---\n";
        cout << "1. Create Graph\n2. Display Adjacency Matrix\n3. BFS Traversal\n4. DFS Traversal\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createGraph();
                break;

            case 2:
                displayMatrix();
                break;

            case 3:
                cout << "Enter starting vertex (0 to " << n - 1 << "): ";
                cin >> start;
                BFS(start);
                break;

            case 4:
                cout << "Enter starting vertex (0 to " << n - 1 << "): ";
                cin >> start;
                DFS(start);
                break;

            case 5:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}
