#include <bits/stdc++.h>
using namespace std;
#define int long long

bool func(int mid, int n, int k, string &s, vector<int> &a)
{
    int pre = 0, op = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > mid)
        {
            if (s[i] == 'B')
            {
                if (!pre)
                {
                    op++;
                    pre = 1; // segment start
                }
            }
            else
                pre = 0; // reset
        }
    }
    return op <= k;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, k;
        string s;
        cin >> n >> k >> s;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        int lo = -1, hi = *max_element(a.begin(), a.end());
        while (hi - lo > 1)
        {
            int mid = (lo + hi) / 2;
            if (func(mid, n, k, s, a))
                hi = mid;
            else
                lo = mid;
        }

        cout << hi << "\n";
    }
    return 0;
}
