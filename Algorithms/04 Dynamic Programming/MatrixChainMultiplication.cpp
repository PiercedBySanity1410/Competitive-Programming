#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout << "Enter number of matrices: ";
    cin >> n;
    vector<pair<int, int>> matrices(n);

    cout << "Enter dimensions (rows cols) of each matrix:\n";
    for (int i = 0; i < n; i++){
        cout << "Matrix " << i + 1 << ": ";
        cin >> matrices[i].first >> matrices[i].second;
    }
    // Validate dimensions
    for (int i = 0; i < n - 1; i++){
        if (matrices[i].second != matrices[i + 1].first){
            cout << "Error: Incompatible matrices at " << i + 1 << " and " << i + 2 << endl;
            return 1;
        }
    }
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int len = 2; len <= n; len++){
        for (int i = 0; i <= n - len; i++){
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++){
                int cost = dp[i][k] + dp[k + 1][j] + matrices[i].first * matrices[k].second * matrices[j].second;
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    cout<<endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++) cout<<setw(10)<<dp[i][j];
        cout<<endl;
    }
    cout << "Minimum number of multiplications: " << dp[0][n - 1] << endl;
    return 0;
}