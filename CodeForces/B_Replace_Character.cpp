#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;
        map<char, int> mp;
        for (auto i : s)
            mp[i]++;
        char mini = '#', maxi = '#';
        int mn = INT_MAX, mx = INT_MIN;
        for (auto i : mp)
        {
            if (mn > i.second)
                mn = i.second, mini = i.first;

            if (mx <= i.second)
                mx = i.second, maxi = i.first;
        }
        for (int i = 0; i < n; i++)
        {
            if (s[i] == mini)
            {
                s[i] = maxi;
                break;
            }
        }
        cout << s << '\n';
    }
    return 0;
}