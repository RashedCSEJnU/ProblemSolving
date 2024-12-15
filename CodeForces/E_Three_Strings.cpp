#include <bits/stdc++.h>
using namespace std;
#define int long long

int func(int i, int j, int k, string &a, string &b, string &c, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int res = 0, left = 0, right = 0;
    if (i - 1 >= 0)
        left = (c[k - 1] == a[i - 1]) + func(i - 1, j, k - 1, a, b, c, dp);
    if (j - 1 >= 0)
        right = (c[k - 1] == b[j - 1]) + func(i, j - 1, k - 1, a, b, c, dp);
    res = max(res, max(left, right));

    return dp[i][j] = res;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        string a, b, c;
        cin >> a >> b >> c;
        int an = a.length(), bn = b.length(), cn = c.length();
        vector<vector<int>> dp(an + 1, vector<int>(bn + 1, -1));
        int ans = func(an, bn, cn, a, b, c, dp);
        cout << cn - ans << '\n';
    }
    return 0;
}