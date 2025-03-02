#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int longestPalindromicSubsequence(string s, int k)
    {
        int n = s.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(k + 1, 0)));
        for (int i = 0; i < n; i++)
        {
            for (int cost = 0; cost <= k; cost++)
            {
                dp[i][i][cost] = 1;
            }
        }

        for (int len = 2; len <= n; len++)
        {
            for (int i = 0; i + len - 1 < n; i++)
            {
                int j = i + len - 1;
                for (int cost = 0; cost <= k; cost++)
                {
                    dp[i][j][cost] = max(dp[i][j][cost], dp[i + 1][j][cost]);
                    dp[i][j][cost] = max(dp[i][j][cost], dp[i][j - 1][cost]);
                    int diff = abs(s[i] - s[j]);
                    int d = min(diff, 26 - diff);
                    if (cost >= d)
                    {
                        int candidate = 2;
                        if (i + 1 <= j - 1)
                            candidate += dp[i + 1][j - 1][cost - d];
                        dp[i][j][cost] = max(dp[i][j][cost], candidate);
                    }
                }
            }
        }
        return dp[0][n - 1][k];
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
    }
    return 0;
}