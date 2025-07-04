#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve(vector<vector<string>> &result, vector<int> &sol, int j, int n, bool *rows, bool (*diag)[2])
{
    if (j == n)
    {
        vector<string> solu(n,string(n,'.'));
        for(int i=0;i<n;i++){
            solu[i][sol[i]]='Q';
        }
        result.push_back(solu);
        return;
    }

    for (int i = 0; i < n; ++i)
    {
        int d2 = i - j + n - 1;
        if (!rows[i] && !diag[i + j][0] && !diag[d2][1])
        {
            rows[i] = diag[i + j][0] = diag[d2][1] = true;
            sol[i] = j;
            solve(result, sol, j + 1, n, rows, diag);
            sol[i] = -1;
            rows[i] = diag[i + j][0] = diag[d2][1] = false;
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    if (n == 1)
        return {{"Q"}};
    if (n < 4)
        return {};

    vector<int> sol(n,-1);
    vector<vector<string>> result;

    bool *rows = new bool[n]{};
    bool (*diag)[2] = new bool[2 * n][2]{};

    solve(result, sol, 0, n, rows, diag);

    delete[] rows;
    delete[] diag;

    return result;
}

void printSolutions(const vector<vector<string>> &solutions)
{
    for (const auto &solution : solutions)
    {
        for (const auto &row : solution)
        {
            cout << row << endl;
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    vector<vector<string>> solutions = solveNQueens(n);

    if (solutions.empty())
    {
        cout << "No solutions exist for n = " << n << endl;
    }
    else
    {
        cout << "Total solutions: " << solutions.size() << endl;
        printSolutions(solutions);
    }

    return 0;
}
