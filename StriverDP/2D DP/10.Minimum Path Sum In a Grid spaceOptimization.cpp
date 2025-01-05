#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minPathSum(vector<vector<int>> &v)
    {
        int n = v.size(), m = v[0].size();
        vector<int> prev(m, INT_MAX); // Stores the previous row's results

        for (int i = 0; i < n; i++)
        {
            vector<int> cur(m, INT_MAX); // Current row's results
            for (int j = 0; j < m; j++)
            {
                if (i == 0 && j == 0)
                {
                    cur[j] = v[i][j]; // Top-left corner
                }
                else
                {
                    if (i > 0)
                        cur[j] = min(cur[j], prev[j] + v[i][j]); // Add from the cell above
                    if (j > 0)
                        cur[j] = min(cur[j], cur[j - 1] + v[i][j]); // Add from the cell on the left
                }
            }
            prev = cur; // Move current row to previous
        }
        return prev[m - 1]; // Bottom-right corner result
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
