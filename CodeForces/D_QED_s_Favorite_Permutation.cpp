#include <bits/stdc++.h>
using namespace std;
<<<<<<< HEAD
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;

        vector<int> v(n + 1), preMax(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> v[i];
            preMax[i] = max(v[i], preMax[i - 1]);
        }

        string s;
        cin >> s;
        s = '#' + s;

        int badBlock = 0;
        auto func = [&](int i, int x)
        {
            if (i < n && s[i] == 'L' && s[i + 1] == 'R' && preMax[i] > i)
                badBlock += x;
        };

        for (int i = 1; i <= n; i++)
        {
            if (preMax[i] > i)
                func(i, 1);
        }

        while (q--)
        {
            int i;
            cin >> i;

            func(i, -1), func(i - 1, -1);

            s[i] = (s[i] == 'R' ? 'L' : 'R');

            func(i, 1), func(i - 1, 1);

            cout << (!badBlock ? "YES\n" : "NO\n");
        }
    }
=======
class Solution
{
private:
#include <bits/stdc++.h>

    void tabulation(string &s1, string &s2, vector<vector<int>> &dp)
    {
        int n1 = s1.size(), n2 = s2.size();
        for (int i = 1; i <= n1; i++)
        {
            for (int j = 1; j <= n2; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    string getLCS(string &s, string &t, vector<vector<int>> &dp)
    {
        string ans;
        int i = s.length(), j = t.length();
        while (i && j)
        {
            if (s[i - 1] == t[j - 1])
            {
                ans.push_back(s[i - 1]);
                i--, j--;
            }
            else if (dp[i - 1][j] > dp[i][j - 1])
                i--;
            else
                j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

public:
    // Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string &s, string &t)
    {
        int n1 = s.size(), n2 = t.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        tabulation(s, t, dp);
        string common = getLCS(s, t, dp);
        if (common.length() == 0)
            return s.length() + t.length();
        string ans;
        int n3 = common.length(), i = 0, j = 0, k = 0;
        while (i < n1 && j < n2 && k < n3)
        {
            if (s[i] == t[j])
            {
                ans.push_back(s[i]);
                i++, j++, k++;
            }
            else if (s[i] == common[k])
                ans.push_back(t[j++]);
            else if (t[j] == common[k])
                ans.push_back(s[i++]);
            else
            {
                ans.push_back(s[i++]);
                ans.push_back(t[j++]);
            }
        }
        while (i < n1)
            ans.push_back(s[i++]);
        while (j < n2)
            ans.push_back(t[j++]);
        return ans.length();
    }
};
int main()
{
    string s, t;
    cin >> s >> t;
    Solution ob;
    cout << ob.shortestCommonSupersequence(s, t) << '\n';
>>>>>>> 01d9dd3 (QED)
    return 0;
}