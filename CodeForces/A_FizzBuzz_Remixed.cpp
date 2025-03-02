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
        int n;
        cin >> n;
        if (n < 15)
        {
            if (n < 3)
                cout << n + 1 << '\n';
            else
                cout << 3 << '\n';
            continue;
        }
        int div = n / 15;
        int rem = n % 15;
        int ans = div * 3;
        if (rem < 3)
            ans += rem + 1;
        else
            ans += 3;
        cout << ans << '\n';
    }
    return 0;
}