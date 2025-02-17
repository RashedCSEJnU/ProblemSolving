#include <bits/stdc++.h>
using namespace std;
#define int long long
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int a, b, dif;
        cin >> a >> b;
        if (a < b)
            swap(a, b);

        if (a == b)
            cout << 0 << ' ' << 0 << '\n';
        else if (a - b == 1)
            cout << 1 << ' ' << 0 << '\n';
        else
        {
            int dif = a - b;
            int low = (a / dif) * dif;
            int ans = a - low;
            int high = ((a + dif - 1) / dif) * dif;
            ans = min(ans, high - a);
            cout << dif << ' ' << ans << '\n';
        }
    }
    return 0;
}