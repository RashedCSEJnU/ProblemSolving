#include <bits/stdc++.h>
using namespace std;

vector<string> allUniquelongestCommonSubsequence(string s, string t)
{
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (s[i - 1] == t[j - 1])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
        }
    }

    set<string> res;
    map<pair<int, int>, set<string>> memo;
    function<set<string>(int, int)> printAllLCS = [&](int i, int j)
    {
        if (i == 0 || j == 0)
            return set<string>{""};

        if (memo.count({i, j}))
            return memo[{i, j}];

        set<string> result;
        if (s[i - 1] == t[j - 1])
        {
            for (auto str : printAllLCS(i - 1, j - 1))
                result.insert(str + s[i - 1]);
        }
        else
        {
            if (dp[i - 1][j] >= dp[i][j - 1])
                result = printAllLCS(i - 1, j);
            if (dp[i][j - 1] >= dp[i - 1][j])
            {
                auto temp = printAllLCS(i, j - 1);
                result.insert(temp.begin(), temp.end());
            }
        }
        return memo[{i, j}] = result;
    };

    res = printAllLCS(n, m);
    return vector<string>(res.begin(), res.end());
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    string s, t;
    cin >> s >> t;

    auto it = allUniquelongestCommonSubsequence(s, t);
    for (auto i : it)
        cout << i << ' ';
    cout << endl;

    return 0;
}