#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int func(vector<vector<int>> &matrix, int r, int c, vector<vector<int>> &dp)
    {
        if (r == 0 and c < matrix[0].size() and c >= 0)
            return matrix[r][c];
        if (c >= matrix[0].size() or c < 0)
            return INT_MAX;

        if (dp[r][c] != INT_MAX)
            return dp[r][c];
        return dp[r][c] = matrix[r][c] + min(min(func(matrix, r - 1, c + 1, dp), func(matrix, r - 1, c, dp)), func(matrix, r - 1, c - 1, dp));
    }
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> dp(rows + 1, vector<int>(cols + 1, INT_MAX));
        int ans = INT_MAX;
        for (int c = 0; c < cols; c++)
        {
            ans = min(ans, func(matrix, rows - 1, c, dp));
        }
        return ans;
    }
};
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> matrix[i][j];
        }
    }
    Solution ob;
    cout << ob.minFallingPathSum(matrix) << endl;
}
