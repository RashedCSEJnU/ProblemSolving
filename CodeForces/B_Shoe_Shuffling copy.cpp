#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        map<int, int> mp;
        for (auto &i : v)
        {
            cin >> i;
            mp[i]++;
        }
        bool flag = 0;
        for (auto [f, s] : mp)
        {
            if (s == 1)
                flag = 1;
        }
        if (flag)
        {
            cout << -1 << '\n';
            continue;
        }
        int prev = 1;
        for (int i = 1; i < n; i++)
        {
            if (v[i] == v[i - 1])
                cout << i + 1 << ' ';
            else
            {
                cout << prev << ' ';
                prev = i + 1;
            }
        }
        cout << prev << '\n';
    }
    return 0;
}