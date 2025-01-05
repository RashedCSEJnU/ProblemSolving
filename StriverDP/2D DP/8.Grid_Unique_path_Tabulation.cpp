#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int uniquePaths(int n, int m)
    {
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        dp[1][1] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
                dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
        }
        return dp[n][m];
    }
};

int main()
{
    int m, n;
    cin >> m >> n;
    Solution obj;
    cout << obj.uniquePaths(m, n) << endl;
    return 0;
}