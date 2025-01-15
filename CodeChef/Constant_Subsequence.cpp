#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int sz;
        cin >> sz;
        vector<int> pos, neg;
        for (int i = 0; i < sz; i++)
        {
            int x;
            cin >> x;
            if (x >= 0)
                pos.push_back(x);
            else
                neg.push_back(x);
        }

        auto check = [&](int mid) -> bool
        {
            int sum = 0, j = 0;
            for (int i = 0; i < pos.size(); i++)
            {
                if (pos[i] > mid)
                    return false;

                sum += pos[i];
                while (sum > mid && j < neg.size())
                {
                    sum += neg[j++];
                    sum = max(sum, pos[i]);
                }
                if (sum > mid)
                    return false;
            }
            return true;
        };

        int lo = 0, hi = 1e16;
        while (hi - lo > 1)
        {
            int mid = (lo + hi) / 2;
            if (check(mid))
                hi = mid;
            else
                lo = mid;
        }

        for (int i = max(lo - 3, 0LL); i <= lo + 3; i++)
        {
            if (check(i))
            {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}
