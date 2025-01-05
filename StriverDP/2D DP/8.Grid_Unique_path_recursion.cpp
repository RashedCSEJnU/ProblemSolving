#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int func(int i, int j, int n, int m, vector<vector<int>> &dp)
    {
        if (i == n && j == m)
            return 1;
        if (i > n || j > m)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int ans = func(i + 1, j, n, m, dp) + func(i, j + 1, n, m, dp);
        return dp[i][j] = ans;
    }

public:
    int uniquePaths(int n, int m)
    {
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return func(1, 1, n, m, dp);
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