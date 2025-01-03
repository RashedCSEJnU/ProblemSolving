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
        int n, a, b, c;
        cin >> n >> a >> b >> c;
        int total = a + b + c;
        int cnt = n / total;
        int ans = cnt * 3;
        int rem = n % total;
        if (rem > 0)
        {
            ans++;
            rem -= a;
        }
        if (rem > 0)
        {
            ans++;
            rem -= b;
        }
        if (rem > 0)
        {
            ans++;
            rem -= c;
        }
        cout << ans << '\n';
    }
    return 0;
}