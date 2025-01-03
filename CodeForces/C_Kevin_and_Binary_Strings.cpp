#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(v) v.begin(), v.end()

vector<int> valueCal(const string &s, int l1, int r1, int l2, int r2)
{
    string s1 = s.substr(l1, r1 - l1 + 1);
    string s2 = s.substr(l2, r2 - l2 + 1);

    reverse(all(s1));
    reverse(all(s2));

    while (s1.size() < s2.size())
        s1 += '0';
    while (s2.size() < s1.size())
        s2 += '0';

    reverse(all(s1));
    reverse(all(s2));

    vector<int> xorResult(s1.size());
    for (int i = 0; i < s1.length(); i++)
    {
        xorResult[i] = (s1[i] - '0') ^ (s2[i] - '0');
    }

    return xorResult;
}

bool isGreaterThan(const vector<int> &xor1, const vector<int> &xor2)
{
    for (int i = 0; i < xor1.size(); ++i)
    {
        if (xor1[i] > xor2[i])
            return true;
        if (xor1[i] < xor2[i])
            return false;
    }
    return false;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;
        int n = s.length();
        int idx = -1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                idx = i;
                break;
            }
        }
        if (idx == -1)
        {
            cout << 1 << ' ' << n << ' ' << 1 << ' ' << 1 << '\n';
            continue;
        }

        int range = n - idx, value = INT_MIN;
        vector<int> maxXorResult;
        pair<int, int> bestPair = {-1, -1};

        for (int i = 0; i <= idx; i++)
        {
            int l2 = i, r2 = i + range - 1;
            vector<int> xorResult = valueCal(s, 0, n - 1, l2, r2);

            if (maxXorResult.empty() || isGreaterThan(xorResult, maxXorResult))
            {
                maxXorResult = xorResult;
                bestPair = {l2 + 1, r2 + 1};
            }
        }

        cout << 1 << " " << n << " " << bestPair.first << " " << bestPair.second << '\n';
    }

    return 0;
}
