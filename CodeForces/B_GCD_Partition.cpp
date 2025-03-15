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
        int n, total = 0, sum = 0, ans = 0;
        cin >> n;
        vector<int> v(n);
        for (auto &i : v)
        {
            cin >> i;
            total += i;
        }
        for (int i = 0; i < n - 1; i++)
        {
            sum += v[i];
            ans = max(ans, __gcd(sum, total - sum));
        }
        cout << ans << '\n';
    }
    return 0;
}