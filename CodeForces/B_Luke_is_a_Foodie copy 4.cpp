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
        int n, x;
        cin >> n >> x;
        vector<int> v(n);
        for (int &i : v)
            cin >> i;
        int ans = 0, mini = v[0], maxi = v[0];
        for (int i = 1; i < n; i++)
        {
            mini = min(mini, v[i]);
            maxi = max(maxi, v[i]);
            if (maxi - mini > 2 * x)
            {
                ans++;
                mini = maxi = v[i];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}