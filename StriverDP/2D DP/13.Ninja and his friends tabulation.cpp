#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int n, int m, vector<vector<int>> &grid)
    {
        int dp[n][m][m];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == j)
                    dp[n - 1][i][j] = grid[n - 1][j];
                else
                    dp[n - 1][i][j] = grid[n - 1][i] + grid[n - 1][j];
            }
        }

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j1 = 0; j1 < m; j1++)
            {
                for (int j2 = 0; j2 < m; j2++)
                {
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
                                currentValue += dp[i + 1][newJ1][newJ2];
                                maxi = max(maxi, currentValue);
                            }
                        }
                    }
                    dp[i][j1][j2] = maxi;
                }
            }
        }
        return dp[0][0][m - 1];
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