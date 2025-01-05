#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minimumTotal(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<int> dp(n, INT_MAX);
        for (int i = 0; i < n; i++)
        {
            vector<int> temp(n, INT_MAX);
            for (int j = 0; j <= i; j++)
            {
                if (i == 0 && j == 0)
                    temp[j] = grid[i][j];
                else
                {
                    long up = INT_MAX, upLeft = INT_MAX;
                    if (i > 0)
                        up = dp[j];
                    if (j > 0)
                        upLeft = dp[j - 1];
                    temp[j] = grid[i][j] + min(up, upLeft);
                }
            }
            dp = temp;
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
            ans = min(ans, dp[i]);
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