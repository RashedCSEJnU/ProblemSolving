#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        // Create a dp table to store the minimum falling path sum at each cell
        vector<vector<int>> dp = matrix; // Copy the matrix into dp (initially same)

        // Iterate over the matrix from the second row to the last row
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int bestAbove = dp[i - 1][j]; // Move straight down
                if (j > 0)
                {
                    bestAbove = min(bestAbove, dp[i - 1][j - 1]); // Move diagonally left
                }
                if (j < m - 1)
                {
                    bestAbove = min(bestAbove, dp[i - 1][j + 1]); // Move diagonally right
                }
                dp[i][j] += bestAbove; // Update the dp value for the current cell
            }
        }

        // The answer will be the minimum value in the last row
        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
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
