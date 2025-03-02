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
        int n, k, p;
        cin >> n >> k >> p;
        k = abs(k);
        int ans = (k + p - 1) / p;
        if (p * n < k)
            ans = -1;
        cout << ans << '\n';
    }
    return 0;
}