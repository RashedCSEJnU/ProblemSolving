#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
class Solution
{
private:
    void getString(int i, int j, string &s, string &t, string tmp, vector<string> &ans, unordered_set<string> &mp, vector<vector<int>> &dp)
    {
        if (i == 0 || j == 0)
        {
            reverse(tmp.begin(), tmp.end());
            ans.push_back(tmp);
            // reverse(tmp.begin(), tmp.end());
            return;
        }

        string key = to_string(i) + to_string(j) + tmp;

        if (mp.find(key) != mp.end())
            return;

        mp.insert(key);

        if (s[i - 1] == t[j - 1])
        {
            tmp.push_back(s[i - 1]);
            getString(i - 1, j - 1, s, t, tmp, ans, mp, dp);
            // tmp.pop_back();
            return;
        }
        if (dp[i - 1][j] == dp[i][j])
            getString(i - 1, j, s, t, tmp, ans, mp, dp);
        if (dp[i][j - 1] == dp[i][j])
            getString(i, j - 1, s, t, tmp, ans, mp, dp);
    }

public:
    vector<string> all_longest_common_subsequences(string s, string t)
    {
        int n = s.length(), m = t.length(), len = 0;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        vector<string> v;
        unordered_set<string> mp;
        string tmp;

        getString(n, m, s, t, tmp, v, mp, dp);

        sort(all(v));
        v.resize(unique(all(v)) - v.begin());

        return v;
    }
};
int main()
{
    string s, t;
    cin >> s >> t;
    Solution ob;
    auto it = ob.all_longest_common_subsequences(s, t);

    for (auto val : it)
        cout << val << ' ';
    cout << '\n';

    return 0;
}