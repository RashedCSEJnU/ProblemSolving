#include <bits/stdc++.h>
using namespace std;

vector<string> all_longest_common_subsequences(string s, string t)
{
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int len = dp[n][m];
    vector<string> result;
    unordered_set<string> seen;

    stack<tuple<int, int, vector<char>>> st;
    st.push(make_tuple(n, m, vector<char>()));

    while (!st.empty())
    {
        auto current_tuple = st.top();
        st.pop();

        int i = get<0>(current_tuple);
        int j = get<1>(current_tuple);
        vector<char> current = get<2>(current_tuple);

        if (current.size() == len)
        {
            string temp(current.rbegin(), current.rend()); // Reverse and construct string
            if (seen.find(temp) == seen.end())
            {
                result.push_back(temp);
                seen.insert(temp);
            }
            continue;
        }

        if (i == 0 || j == 0)
            continue;

        if (s[i - 1] == t[j - 1])
        {
            auto next = current;
            next.push_back(s[i - 1]); // Avoid modifying the original vector
            st.push(make_tuple(i - 1, j - 1, next));
        }
        else
        {
            if (dp[i - 1][j] >= dp[i][j - 1])
                st.push(make_tuple(i - 1, j, current));
            if (dp[i][j - 1] >= dp[i - 1][j])
                st.push(make_tuple(i, j - 1, current));
        }
    }

    sort(result.begin(), result.end());
    return result;
}

int main()
{
    string s, t;
    cin >> s >> t;
    auto it = all_longest_common_subsequences(s, t);

    for (auto val : it)
        cout << val << ' ';
    cout << '\n';
}