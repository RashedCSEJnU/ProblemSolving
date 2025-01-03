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
        int n, k, ans = 0;
        cin >> n >> k;
        vector<int> a(n), b(n), v;
        for (int &i : a)
        {
            cin >> i;
            v.push_back(i);
        }
        for (int &i : b)
        {
            cin >> i;
            v.push_back(i);
        }
        sort(all(a)), sort(all(b));
        for (auto it : v)
        {
            int less1 = lower_bound(all(a), it) - a.begin();
            int less2 = lower_bound(all(b), it) - b.begin();
            if (less1 - less2 <= k)
                ans = max(ans, (n - less2) * it);
        }
        cout << ans << '\n';
    }
    return 0;
}