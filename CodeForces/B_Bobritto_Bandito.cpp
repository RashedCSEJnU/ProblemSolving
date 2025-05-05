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
        int n, m, l, r;
        cin >> n >> m >> l >> r;
        int rightMin = min(r, m);
        int leftMin = min(abs(l), m - rightMin);
        cout << -leftMin << ' ' << rightMin << '\n';
    }
    return 0;
}