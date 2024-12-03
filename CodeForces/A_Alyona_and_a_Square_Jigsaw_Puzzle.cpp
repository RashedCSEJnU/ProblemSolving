#include <bits/stdc++.h>
using namespace std;
#define int long long

bool ok(int n)
{
    int x = sqrt(n);
    int val = x * x;
    return x & 1 && val == n;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, ans = 0, sum = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            sum += x;
            if (ok(sum))
                ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}