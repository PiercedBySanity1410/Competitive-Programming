#include <iostream>
#include<vector>
using namespace std;

class UnionFind {
public:
    int*parent,*rank;
    int size;
    UnionFind(int n) :size(n){
        parent=new int[n];
        rank=new int[n]{};
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    ~UnionFind(){
        delete parent;
        delete rank;
    }
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) {
            return false;
        }

        // Union by rank
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }

        return true;
    }
};
// class UnionFind {
// public:
//     int* parent;
//     int* rank;
//     int* componentSize;
//     bool* active;
//     int size;
//     long long totalSubarrays;

//     UnionFind(int n) : size(n), totalSubarrays(0) {
//         parent = new int[n];
//         rank = new int[n]{};
//         componentSize = new int[n]{};
//         active = new bool[n]{};

//         for (int i = 0; i < n; i++) {
//             parent[i] = i;
//         }
//     }

//     ~UnionFind() {
//         delete[] parent;
//         delete[] rank;
//         delete[] componentSize;
//         delete[] active;
//     }

//     int find(int x) {
//         if (parent[x] != x)
//             parent[x] = find(parent[x]);
//         return parent[x];
//     }

//     static long long subarrays(long long k) {
//         return k * (k + 1) / 2;
//     }

//     // Activate a node
//     void activate(int x) {
//         if (active[x]) return;

//         active[x] = true;
//         componentSize[x] = 1;
//         totalSubarrays += 1;
//     }

//     bool unionSets(int x, int y) {
//         if (!active[x] || !active[y]) return false;

//         int rootX = find(x);
//         int rootY = find(y);

//         if (rootX == rootY) return false;

//         long long sizeX = componentSize[rootX];
//         long long sizeY = componentSize[rootY];

//         // Remove old contributions
//         totalSubarrays -= subarrays(sizeX);
//         totalSubarrays -= subarrays(sizeY);

//         // Union by rank
//         if (rank[rootX] > rank[rootY]) {
//             parent[rootY] = rootX;
//             componentSize[rootX] += componentSize[rootY];
//             totalSubarrays += subarrays(componentSize[rootX]);
//         } else if (rank[rootX] < rank[rootY]) {
//             parent[rootX] = rootY;
//             componentSize[rootY] += componentSize[rootX];
//             totalSubarrays += subarrays(componentSize[rootY]);
//         } else {
//             parent[rootY] = rootX;
//             componentSize[rootX] += componentSize[rootY];
//             rank[rootX]++;
//             totalSubarrays += subarrays(componentSize[rootX]);
//         }
//         return true;
//     }

//     long long getTotalSubarrays() const {
//         return totalSubarrays;
//     }
// };
bool hasCycle(int n, vector<pair<int, int>>& edges) {
    UnionFind uf(n);

    for (auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;

        if (!uf.unionSets(u, v)) {
            return true;  // Cycle detected
        }
    }

    return false;  // No cycle found
}

int main() {
    int n = 4;  // Number of vertices
    vector<pair<int, int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 0}};  // Graph edges

    if (hasCycle(n, edges)) {
        cout << "Graph contains a cycle" << endl;
    } else {
        cout << "Graph does not contain a cycle" << endl;
    }

    return 0;
}
