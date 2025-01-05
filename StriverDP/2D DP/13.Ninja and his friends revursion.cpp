#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int func(int n, int m, vector<vector<int>> &grid, int i, int j1, int j2, vector<vector<vector<int>>> &dp)
    {
        if (i == n)
            return 0;
        if (dp[i][j1][j2] != -1)
            return dp[i][j1][j2];
        int maxi = INT_MIN;
        for (int di = -1; di <= 1; di++)
        {
            for (int dj = -1; dj <= 1; dj++)
            {
                int newJ1 = j1 + di;
                int newJ2 = j2 + dj;
                if (newJ1 >= 0 && newJ2 >= 0 && newJ1 < m && newJ2 < m)
                {
                    int currentValue;
                    if (j1 == j2)
                        currentValue = grid[i][j1];
                    else
                        currentValue = grid[i][j1] + grid[i][j2];
                    currentValue += func(n, m, grid, i + 1, newJ1, newJ2, dp);
                    maxi = max(maxi, currentValue);
                }
            }
        }
        return dp[i][j1][j2] = maxi;
    }

    int solve(int n, int m, vector<vector<int>> &grid)
    {
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return func(n, m, grid, 0, 0, m - 1, dp);
    }
};
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    }
    Solution obj;
    cout << obj.solve(n, m, grid) << endl;
    return 0;
}