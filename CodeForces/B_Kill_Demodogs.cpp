#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

long long power(long long a, long long b, long long m)
{
    a %= m;
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
int squre(int n)
{
    int ans = n * (n + 1) % mod * (2 * n + 1) % mod * (power(6, mod - 2, mod)) % mod;
    return ans;
}
int serise(int n)
{
    int ans = n * (n + 1) % mod * power(2, mod - 2, mod) % mod;
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int ans = ((squre(n) + squre(n - 1) + serise(n - 1)) % mod * 2022) % mod;
        cout << ans << '\n';
    }
    return 0;
}