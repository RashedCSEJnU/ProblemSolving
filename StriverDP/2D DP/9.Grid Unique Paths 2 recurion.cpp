#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int func(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        int n = grid.size(), m = grid[0].size();
        if (i >= n || j >= m || grid[i][j] == 1)
            return 0;
        if (i == n - 1 && j == m - 1)
            return 1;
        if (dp[i][j] != -1)
            return dp[i][j];
        int ans = func(i + 1, j, grid, dp);
        ans += func(i, j + 1, grid, dp);
        return dp[i][j] = ans;
    }
    int uniquePathsWithObstacles(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        int ans = func(0, 0, grid, dp);
        return ans;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> grid[i][j];
        }
    }
    Solution ob;
    cout << ob.uniquePathsWithObstacles(grid) << endl;
    return 0;
}