#include <iostream>
#include <list>
#include <stack>
#include <vector>
using namespace std;

class Edge {
public:
    int u, v;
    Edge(int u, int v) : u(u), v(v) {}
};

class Graph {
    int V;
    list<int>* adj;
    int time;
    int bccCount;

    void BCCUtil(int u, vector<int>& disc, vector<int>& low,
                 stack<Edge>& st, vector<int>& parent);

public:
    Graph(int V);
    ~Graph();
    void addEdge(int u, int v);
    void BCC();
};

Graph::Graph(int V) : V(V), time(0), bccCount(0) {
    adj = new list<int>[V];
}

Graph::~Graph() {
    delete[] adj;
}

void Graph::addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);  // Because the graph is undirected
}

void Graph::BCCUtil(int u, vector<int>& disc, vector<int>& low,
                    stack<Edge>& st, vector<int>& parent) {
    disc[u] = low[u] = ++time;
    int children = 0;

    for (int v : adj[u]) {
        if (disc[v] == -1) {
            children++;
            parent[v] = u;
            st.push(Edge(u, v));
            BCCUtil(v, disc, low, st, parent);

            low[u] = min(low[u], low[v]);
            
            // Articulation point condition
            if ((disc[u] == 1 && children > 1) ||
                (disc[u] > 1 && low[v] >= disc[u])) {
                cout << "BCC #" << ++bccCount << ": ";
                while (!(st.top().u == u && st.top().v == v)) {
                    cout << char(st.top().u+'A') << "--" << char(st.top().v+'A') << " ";
                    st.pop();
                }
                cout << char(st.top().u+'A') << "--" << char(st.top().v+'A') << "\n";
                st.pop();
            }
        }
        else if (v != parent[u] && disc[v] < disc[u]) {
            low[u] = min(low[u], disc[v]);
            st.push(Edge(u, v));
        }
    }
}

void Graph::BCC() {
    vector<int> disc(V, -1), low(V, -1), parent(V, -1);
    stack<Edge> st;

    for (int i = 0; i < V; i++) {
        if (disc[i] == -1) {
            BCCUtil(i, disc, low, st, parent);

            // Remaining edges in stack form a component
            if (!st.empty()) {
                cout << "BCC #" << ++bccCount << ": ";
                while (!st.empty()) {
                    cout << char(st.top().u+'A') << "--" << char(st.top().v+'A') << " ";
                    st.pop();
                }
                cout << "\n";
            }
        }
    }
    cout << "Discovery Points: ";
    for (int i = 0; i < V; i++) {
            cout << disc[i] << " ";
    }
    cout<<endl;
    cout << "LOW Points: ";
    for (int i = 0; i < V; i++) {
            cout << low[i] << " ";
    }
    cout<<endl;
    cout << "Total Biconnected Components: " << bccCount << "\n";
}

// Driver code
int main() {
    Graph g(12); // 12 vertices labeled 0 to 11
    g.addEdge(0, 3); // A-D
    g.addEdge(0, 4); // A-E
    g.addEdge(1, 4); // B-E
    g.addEdge(2, 8); // C-I
    g.addEdge(2, 7); // C-H
    g.addEdge(3, 8); // D-I
    g.addEdge(3, 4); // D-E
    g.addEdge(4, 9); // E-J
    g.addEdge(5, 6); // F-G
    g.addEdge(5, 9); // F-J
    g.addEdge(6, 10); // G-K
    g.addEdge(7, 8); // H-I
    g.addEdge(8, 9); // I-J
    g.addEdge(9, 10); // J-K
    g.addEdge(10, 11); // K-L
    g.BCC();
    return 0;
}
