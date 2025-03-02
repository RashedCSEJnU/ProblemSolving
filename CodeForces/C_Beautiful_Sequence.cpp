#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 998244353;

int power(int base, int exp)
{
    int res = 1;
    while (exp > 0)
    {
        if (exp & 1)
            res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return res;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t, N = 200005;
    cin >> t;

    vector<int> pow2(N + 1, 1), inv2(N + 1, 1);
    for (int i = 1; i <= N; i++)
        pow2[i] = (pow2[i - 1] * 2) % MOD;

    for (int i = 0; i <= N; i++)
        inv2[i] = power(pow2[i], MOD - 2);

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];

        vector<int> prefix(n + 1, 0);
        for (int i = 1; i <= n; i++)
            prefix[i] = prefix[i - 1] + (a[i] == 2);

        vector<int> S(n + 2, 0), C(n + 2, 0);

        S[n + 1] = C[n + 1] = 0;
        for (int i = n; i >= 1; i--)
        {
            S[i] = S[i + 1];
            C[i] = C[i + 1];
            if (a[i] == 3)
            {
                S[i] = (S[i] + pow2[prefix[i - 1]]) % MOD;
                C[i]++;
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == 1)
            {
                int ways = ((S[i + 1] * inv2[prefix[i]]) % MOD - C[i + 1]) % MOD;
                if (ways < 0)
                    ways += MOD;
                ans = (ans + ways) % MOD;
            }
        }
        ans %= MOD;
        cout << ans << "\n";
    }
    return 0;
}
