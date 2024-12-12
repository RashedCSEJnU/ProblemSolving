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
        int n, i, c = 0;
        cin >> n;
        vector<int> v(n);
        for (auto &i : v)
            cin >> i;
        int odd = 0, even = 0, od = 0, ev = 0;
        for (int i = 0; i < n; i++)
        {
            if (i & 1)
                odd += v[i], od++;
            else
                even += v[i], ev++;
        }
        c = (odd % od == 0 && even % ev == 0 && even / ev == odd / od);
        cout << (c ? "YES\n" : "NO\n");
    }
    return 0;
}