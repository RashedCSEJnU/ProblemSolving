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
        int x, y, k;
        cin >> x >> y >> k;
        int need = k - 1 + (k * y);
        int ans = (need + x - 2) / (x - 1);
        cout << ans + k << '\n';
    }
    return 0;
}