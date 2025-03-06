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
        vector<pair<int, int>> vp(n);
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            x *= 2;
            vp[i] = {x, i};
        }
        sort(vp.rbegin(), vp.rend());
        int cnt = 1, ans = 0;
        for (int i = 0; i < n; i++)
        {
            auto [value, x] = vp[i];
            v[x] = cnt;
            ans += (value * cnt);
            if (i + 1 < n)
            {
                auto [value1, x1] = vp[i + 1];
                v[x1] = -cnt;
                ans += (value1 * cnt);
                cnt++;
                i++;
            }
        }

        cout << ans << '\n';
        cout << 0 << ' ';
        for (auto val : v)
            cout << val << ' ';
        cout << '\n';
    }
    return 0;
}