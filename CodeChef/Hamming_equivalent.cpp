#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        vector<int> v(n);
        for (auto &i : v)
            cin >> i;

        vector<int> a = v;
        sort(a.begin(), a.end());
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[a[i]] = __builtin_popcount(a[i]);
        }
        bool flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (mp[v[i]] != mp[a[i]])
            {
                flag = 1;
                break;
            }
        }
        cout << (flag ? "NO" : "YES") << endl;
    }
    return 0;
}