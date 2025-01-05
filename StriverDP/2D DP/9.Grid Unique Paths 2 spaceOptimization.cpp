#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();

        // If the starting point or the ending point is an obstacle, return 0
        if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1)
            return 0;

        // Create a 1D DP array for the current row
        vector<long long> dp(m, 0);
        dp[0] = 1; // Starting point

        // Fill the DP array row by row
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (grid[i][j] == 1)
                {
                    dp[j] = 0; // If there's an obstacle, reset the ways to 0
                }
                else
                {
                    // If we are not in the first column, add paths from the left cell
                    if (j > 0)
                    {
                        dp[j] = (dp[j] + dp[j - 1]);
                    }
                }
            }
        }

        // The answer is in the bottom-right corner of the grid
        return dp[m - 1];
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