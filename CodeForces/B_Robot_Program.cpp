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
        int n, x, k, cnt = 0;
        string s;
        cin >> n >> x >> k >> s;

        if (x == 0)
            cnt = 1;

        int pre = -1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'L')
                x--;
            else
                x++;

            if (x == 0)
            {
                cnt++;
                pre = i + 1;
                break;
            }
        }
        // cout << cnt << ' ' << pre << '\n';
        int i = 0, val = 0, rem = k - pre;
        for (; i < n; i++)
        {
            if (s[i] == 'L')
                val--;
            else
                val++;
            if (val == 0)
                break;
        }
        if (rem < 0 || cnt == 0)
        {
            cout << 0 << '\n';
        }
        else if (i == n)
        {
            cout << cnt << '\n';
        }
        else
        {
            int nextCycle = i + 1;
            int total = rem / nextCycle;
            int ans = cnt + total;
            cout << ans << '\n';
        }
    }
    return 0;
}