#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int node, int c, vector<vector<int>> &graph, vector<int> &color) {
    for (int i = 0; i < graph.size(); i++) {
        if (graph[node][i] && color[i] == c) {
            return false;
        }
    }
    return true;
}

bool graphColoringUtil(vector<vector<int>> &graph, int m, vector<int> &color, int node) {
    int n = graph.size();
    if (node == n)
        return true;

    for (int c = 1; c <= m; c++) {
        if (isSafe(node, c, graph, color)) {
            color[node] = c;
            if (graphColoringUtil(graph, m, color, node + 1))
                return true;
            color[node] = 0;
        }
    }

    return false;
}

int findChromaticNumber(vector<vector<int>> &graph) {
    int n = graph.size();
    for (int m = 1; m <= n; m++) {
        vector<int> color(n, 0);
        if (graphColoringUtil(graph, m, color, 0)) {
            cout << "Coloring with " << m << " colors: ";
            for (int c : color)
                cout << c << " ";
            cout << endl;
            return m;
        }
    }
    return n; // worst case
}

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;
    vector<vector<int>> graph(V, vector<int>(V, 0));
    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < V; i++){
        for (int j = 0; j < V; j++){
            cin >> graph[i][j];
        }
    }

    int chromaticNumber = findChromaticNumber(graph);
    cout << "Minimum number of colors required: " << chromaticNumber << endl;

    return 0;
}