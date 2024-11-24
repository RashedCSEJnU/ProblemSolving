#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

int power(int a, int b)
{
    a %= mod;
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, sum = 0;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        stack<pair<int, int>> st; // x,y  where 2^x *y =a[i]

        for (int i = 0; i < n; i++)
        {
            int cnt = 0;
            while (a[i] % 2 == 0)
            {
                a[i] /= 2;
                cnt++;
            }

            while (!st.empty() && (st.top().second <= (power(2, cnt) * 1LL * a[i]) || cnt > 30))
            {
                auto it = st.top();
                st.pop();

                int x = it.first, y = it.second;
                cnt += x;

                sum = ((sum - (power(2, x) * 1LL * y) % mod) + mod) % mod;
                sum = (sum + 0LL + y) % mod;
            }
            st.push({cnt, a[i]});
            sum = (sum + (a[i] * 1LL * power(2, cnt)) % mod) % mod;
            cout << sum << ' ';
        }
        cout << '\n';
    }
    return 0;
}