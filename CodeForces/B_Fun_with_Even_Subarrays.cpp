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
        int n;
        cin >> n;
        vector<int> v(n);
        for (auto &i : v)
            cin >> i;

        int ans = 0, maxi = 0;
        while (maxi < n)
        {
            int ind = n - maxi - 1;
            if (ind < n && ind >= 0 && v[ind] == v.back())
                maxi++;
            else
            {
                ans++;
                maxi *= 2;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}