#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (i == 0 && j == 0)
                    dp[i][j] = grid[i][j];
                else
                {
                    if (i > 0)
                        dp[i][j] = min(dp[i][j] + 0LL, 0LL + grid[i][j] + dp[i - 1][j]);
                    if (i > 0 && j > 0)
                        dp[i][j] = min(dp[i][j] + 0LL, 0LL + grid[i][j] + dp[i - 1][j - 1]);
                }
            }
        }
        int mini = INT_MAX;
        for (int i = 0; i < n; i++)
            mini = min(mini, dp[n - 1][i]);
        return mini;
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