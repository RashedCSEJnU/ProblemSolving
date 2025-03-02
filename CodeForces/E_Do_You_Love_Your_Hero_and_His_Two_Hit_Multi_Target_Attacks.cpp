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

        vector<pair<int, int>> vp;
        int left = 0, right = 1;
        while (n > 0)
        {
            left++;

            if (n == 1)
            {
                vp.push_back({left, right});
                vp.push_back({left, right + 1});
                n = 0;
                break;
            }
            if (n == 2)
            {
                vp.push_back({left, right});
                vp.push_back({left, right + 1});
                vp.push_back({left + 1, right});
                n = 0;
                break;
            }

            int lo = 1, hi = 500, mid;
            while (hi - lo > 1)
            {
                mid = (lo + hi) / 2;
                int value = mid * (mid - 1);
                if (value < 2 * n)
                    lo = mid;
                else
                    hi = mid;
            }
            for (int i = 0; i < lo; i++)
                vp.push_back({left, right++});

            n -= (lo * (lo - 1) / 2);
        }
        if (n > 0)
            vp.push_back({left + 1, 1});

        cout << vp.size() << endl;
        for (auto x : vp)
            cout << x.first << " " << x.second << endl;
        cout << endl;
    }
    return 0;
}