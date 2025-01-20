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
        int n, m;
        cin >> n >> m;
        int ans = 0, x = 0, y = 0;

        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            if (i == 0)
            {
                x = m;
                y = m - 2;
            }
            else
            {
                x += a;
                y += b - 1;
            }
            cout << x << ' ' << y << endl;
        }
        if (n == 1)
            ans = 2 * m + 2 * (m - 2);
        else
            ans = 2 * (x + y);

        cout << ans << endl;
    }
    return 0;
}