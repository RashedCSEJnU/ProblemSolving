#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (auto &i : a)
            cin >> i;
        for (auto &i : b)
            cin >> i;
        sort(a.begin(), a.end()), sort(b.begin(), b.end());
        int ans = 1, flag = 0;
        for (int i = 0; i < n; i++)
        {
            auto it = upper_bound(a.begin(), a.end(), b[i]) - a.begin();
            int boro = i + 1 - it;
            ans *= boro;
            ans %= mod;
            if (b[i] >= a[i])
                flag = 1;
        }
        cout << (flag ? 0 : ans) << '\n';
    }
    return 0;
}