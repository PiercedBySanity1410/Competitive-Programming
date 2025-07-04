#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

// Memoization table: dp[mask][pos]
vector<vector<int>> dp;

int totalCost(int mask, int pos, int n, const vector<vector<int>> &cost) {
    // Base case: all cities visited, return to start
    if (mask == (1 << n) - 1) {
        return cost[pos][0];
    }

    // If already computed
    if (dp[mask][pos] != -1) return dp[mask][pos];

    int ans = INF;
    for (int city = 0; city < n; city++) {
        if (!(mask & (1 << city))) {
            int newCost = cost[pos][city] + totalCost(mask | (1 << city), city, n, cost);
            ans = min(ans, newCost);
        }
    }

    return dp[mask][pos] = ans;
}

int tsp(const vector<vector<int>> &cost) {
    int n = cost.size();
    dp.assign(1 << n, vector<int>(n, -1));  // Initialize dp with -1
    return totalCost(1, 0, n, cost);        // Start from city 0, mask = 1 (city 0 visited)
}

int main() {
    vector<vector<int>> cost = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int res = tsp(cost);
    cout << "Minimum TSP cost: " << res << endl;
    return 0;
}
