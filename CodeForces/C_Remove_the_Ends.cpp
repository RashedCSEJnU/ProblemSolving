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
        int n, ans = 0;
        cin >> n;
        vector<int> v(n), pre(n + 1), suf(n + 1);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        for (int i = 0; i < n; i++)
            pre[i + 1] = pre[i] + max(0LL, v[i]);
        for (int i = n - 1; i >= 0; i--)
            suf[i] = suf[i + 1] + max(0LL, -v[i]);
        for (int i = 0; i <= n; i++)
            ans = max(ans, suf[i] + pre[i]);
        cout << ans << '\n';
    }
    return 0;
}