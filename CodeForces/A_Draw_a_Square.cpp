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
        // (−l,0), (r,0), (0,−d), (0,u)
        int l, r, d, u;
        cin >> l >> r >> d >> u;

        if (l == r && d == u && l == d)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}