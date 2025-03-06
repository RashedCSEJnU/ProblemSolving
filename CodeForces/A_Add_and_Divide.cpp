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
        int a, b, prev = 0;
        cin >> a >> b;

        if (b == 1)
        {
            prev++, b++;
        }
        int ans = 10000, sz = b + 32;
        while (b < sz)
        {
            int sum = 0, tmp = a;
            while (tmp > 0)
            {
                sum++;
                tmp /= b;
            }
            sum += prev;
            ans = min(ans, sum);
            b++, prev++;
        }
        cout << ans << '\n';
    }
    return 0;
}