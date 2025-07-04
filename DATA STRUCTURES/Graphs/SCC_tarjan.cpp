#include <iostream>
#include <vector>
#include <stack>
#include <list>
#include <algorithm>

using namespace std;

class Graph {
    int V;
    vector<list<int>> adj;

    void SCCUtil(int u, vector<int>& disc, vector<int>& low,
                 stack<int>& st, vector<bool>& stackMember, int& time);

public:
    Graph(int V);
    void addEdge(int v, int w);
    void SCC(); // Prints all SCCs
};

Graph::Graph(int V) : V(V), adj(V) {}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

void Graph::SCCUtil(int u, vector<int>& disc, vector<int>& low,
                    stack<int>& st, vector<bool>& stackMember, int& time) {
    disc[u] = low[u] = ++time;
    st.push(u);
    stackMember[u] = true;

    for (int v : adj[u]) {
        if (disc[v] == -1) {
            SCCUtil(v, disc, low, st, stackMember, time);
            low[u] = min(low[u], low[v]);
        }
        else if (stackMember[v]) {
            low[u] = min(low[u], disc[v]);
        }
    }

    if (low[u] == disc[u]) {
        cout << "SCC: ";
        int w;
        do {
            w = st.top(); st.pop();
            cout << w << " ";
            stackMember[w] = false;
        } while (w != u);
        cout << "\n";
    }
}

void Graph::SCC() {
    vector<int> disc(V, -1), low(V, -1);
    vector<bool> stackMember(V, false);
    stack<int> st;
    int time = 0;

    for (int i = 0; i < V; ++i) {
        if (disc[i] == -1) {
            SCCUtil(i, disc, low, st, stackMember, time);
        }
    }
}

int main() {
    vector<pair<int, vector<pair<int, int>>>> testCases = {
        {5, {{1, 0}, {0, 2}, {2, 1}, {0, 3}, {3, 4}}},
        {4, {{0, 1}, {1, 2}, {2, 3}}},
        {7, {{0, 1}, {1, 2}, {2, 0}, {1, 3}, {1, 4}, {1, 6}, {3, 5}, {4, 5}}},
        {11, {
            {0, 1}, {0, 3}, {1, 2}, {1, 4}, {2, 0}, {2, 6}, {3, 2}, {4, 5}, {4, 6},
            {5, 6}, {5, 7}, {5, 8}, {5, 9}, {6, 4}, {7, 9}, {8, 9}, {9, 8}
        }},
        {5, {{0, 1}, {1, 2}, {2, 3}, {2, 4}, {3, 0}, {4, 2}}}
    };

    for (size_t i = 0; i < testCases.size(); ++i) {
        cout << "\nSCCs in graph " << i + 1 << ":\n";
        Graph g(testCases[i].first);
        for (auto& edge : testCases[i].second) {
            g.addEdge(edge.first, edge.second);
        }
        g.SCC();
    }

    return 0;
}
