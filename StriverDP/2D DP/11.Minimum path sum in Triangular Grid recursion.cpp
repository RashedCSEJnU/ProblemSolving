#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int func(int i, int j, int n, vector<vector<int>> &grid,
             vector<vector<int>> &dp)
    {
        if (i == n)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int left = grid[i][j] + func(i + 1, j, n, grid, dp);
        int right = grid[i][j] + func(i + 1, j + 1, n, grid, dp);
        return dp[i][j] = min(left, right);
    }

    int minimumTotal(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int ans = func(0, 0, n, grid, dp);
        return ans;
    }
};
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    Solution s;
    cout << s.minimumTotal(grid) << endl;
}