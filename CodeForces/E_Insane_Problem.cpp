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
        int k, l1, r1, l2, r2;
        cin >> k >> l1 >> r1 >> l2 >> r2;

        int ans = 0, val = 1;
        while (val <= r2)
        {
            int miniY = max(l2, val * l1);
            int maxiY = min(r2, val * r1);

            if (miniY <= maxiY)
            {
                int miniX = (miniY + val - 1) / val;
                int maxiX = maxiY / val;

                if (miniX <= maxiX)
                    ans += maxiX - miniX + 1;
            }

            if (val * 1LL * k > 1LL * r2)
                break;

            val *= k;
        }

        cout << ans << '\n';
    }
    return 0;
}