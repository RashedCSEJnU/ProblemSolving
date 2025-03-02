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
        int n, k, b, s, sum = 0, bsum = 0;
        cin >> n >> k >> b >> s;
        vector<int> v(n);
        sum = v[0] = b * k;
        for (int i = 0; i < n; i++)
        {
            int mini = min(s - sum, k - 1);
            v[i] += mini;
            if (i)
                sum += v[i];
            else
                sum += mini;
            bsum += (v[i] / k);
        }
        if (sum == s && bsum == b)
        {
            for (auto val : v)
                cout << val << ' ';
            cout << '\n';
        }
        else
            cout << -1 << '\n';
    }
    return 0;
}