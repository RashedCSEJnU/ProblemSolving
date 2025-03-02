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
        int n, k, two = 0, ans = INT_MAX;
        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            two += (x % 2 == 0);

            int rem = x % k;
            if (rem == 0)
                rem = k;
            ans = min(ans, k - rem);
        }

        if (k == 4)
            ans = min(ans, 2 - min(two, 2LL));

        cout << ans << '\n';
    }
    return 0;
}