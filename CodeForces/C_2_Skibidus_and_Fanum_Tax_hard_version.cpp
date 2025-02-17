#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(v) v.begin(), v.end()
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m);
        for (int &i : a)
            cin >> i;
        for (int &i : b)
            cin >> i;

        sort(all(b));
        bool flag = false;
        int pre = min(b[0] - a[0], a[0]);
        a[0] = pre;
        for (int i = 1; i < n; i++)
        {
            int val = pre + a[i];
            auto it = lower_bound(all(b), val);
            auto it2 = upper_bound(all(b), val);

            if (it == b.end())
            {
                pre = max(a[i], pre);
                continue;
            }
            int newVal = *it - a[i];
            int miniVal = min(a[i], newVal);
            if (miniVal >= pre)
                a[i] = miniVal;
            else if (newVal >= pre)
                a[i] = newVal;

            pre = a[i];
        }

        // for (auto val : a)
        //     cout << val << ' ';
        // cout << '\n';

        flag |= !is_sorted(all(a));
        cout << (flag ? "NO" : "YES") << '\n';
    }
    return 0;
}