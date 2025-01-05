#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        vector<int> prev = matrix[0];
        for (int i = 1; i < n; i++)
        {
            vector<int> cur(n, INT_MAX);
            for (int j = 0; j < n; j++)
            {
                cur[j] = min(cur[j], matrix[i][j] + prev[j]);
                if (j > 0)
                    cur[j] = min(cur[j], matrix[i][j] + prev[j - 1]);
                if (j + 1 < n)
                    cur[j] = min(cur[j], matrix[i][j] + prev[j + 1]);
            }
            prev = cur;
        }
        int mini = *min_element(prev.begin(), prev.end());
        return mini;
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
