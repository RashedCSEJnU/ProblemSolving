#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSumPathUtil(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp)
    {
        if (i == 0 && j == 0)
            return matrix[0][0];
        if (i < 0 || j < 0)
            return 1e9;
        if (dp[i][j] != -1)
            return dp[i][j];
        int up = matrix[i][j] + minSumPathUtil(i - 1, j, matrix, dp);
        int left = matrix[i][j] + minSumPathUtil(i, j - 1, matrix, dp);
        return dp[i][j] = min(up, left);
    }
    int minPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return minSumPathUtil(n - 1, m - 1, matrix, dp);
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
    cout << ob.minPathSum(matrix) << endl;
    return 0;
}