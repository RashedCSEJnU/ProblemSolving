#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, ans = INT_MAX;
    cin >> n;

    auto valid = [&](int x) -> int
    {
        int series = x * (x - 1);
        int remaining = n - series;
        int ans = remaining / x;
        ans += 2 * (x - 1);
        int rem = remaining % x;
        if (rem)
            ans++;
        return ans;
    };

    for (int i = 1; i * i <= n; i++)
        ans = min(ans, valid(i));

    cout << ans << '\n';
    return 0;
}