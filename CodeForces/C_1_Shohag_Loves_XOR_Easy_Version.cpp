#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);

    int t;
    cin >> t;

    for (int tc = 0; tc < t; ++tc)
    {
        int x, m, ans = 0;
        cin >> x >> m;

        for (int i = 1; i <= (min(2 * x, m)); i++)
        {
            if (i == x)
                continue;

            int xorVal = x ^ i;
            if (x % xorVal == 0 || i % xorVal == 0)
                ans++;
        }
        cout << ans << '\n';
    }

    return 0;
}