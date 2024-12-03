#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, maxi = INT_MIN, ans = 0;
        cin >> n;
        int a[n], b[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];

        for (int i = 0; i < n; i++)
        {
            ans += max(a[i], b[i]);
            maxi = max(maxi, min(a[i], b[i]));
        }
        cout << ans + maxi << '\n';
    }
    return 0;
}