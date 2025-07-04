#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

#define INF 1e9 // A very large value representing infinity

class Graph {
    int V; // Number of vertices
    vector<vector<int>> dist; // Distance matrix

public:
    Graph(int vertices) : V(vertices), dist(vertices, vector<int>(vertices, INF)) {
        for (int i = 0; i < V; ++i) {
            dist[i][i] = 0; // Distance from a vertex to itself is 0
        }
    }

    // Add an edge to the graph
    void addEdge(int u, int v, int weight) {
        dist[u][v] = weight;
    }

    // Floyd-Warshall Algorithm
    void floydWarshall() {
        for (int k = 0; k < V; ++k) { // Intermediate vertex
            for (int i = 0; i < V; ++i) { // Source vertex
                for (int j = 0; j < V; ++j) { // Destination vertex
                    if (dist[i][k] != INF && dist[k][j] != INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        // Check for negative weight cycles
        for (int i = 0; i < V; ++i) {
            if (dist[i][i] < 0) {
                cout << "Graph contains a negative weight cycle.\n";
                return;
            }
        }

        // Print the result
        printDistances();
    }

    // Print the distance matrix
    void printDistances() {
        cout << "Shortest distances between every pair of vertices:\n";
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (dist[i][j] == INF)
                    cout << setw(5) << "INF";
                else
                    cout << setw(5) << dist[i][j];
            }
            cout << '\n';
        }
    }
};

// Example usage
int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    Graph g(V);

    cout << "Enter the number of edges: ";
    cin >> E;

    cout << "Enter edges (u v weight), use a large number for INF:\n";
    for (int i = 0; i < E; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        g.addEdge(u, v, weight);
    }

    cout << "Floyd-Warshall Algorithm Output:\n";
    g.floydWarshall();

    return 0;
}