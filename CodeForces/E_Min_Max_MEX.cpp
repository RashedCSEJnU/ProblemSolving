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
        // binary search
        int n, k;
        cin >> n >> k;

        vector<int> v(n);
        for (auto &i : v)
            cin >> i;

        auto check = [&](int mid) -> bool
        {
            set<int> st;
            int seg = 0;
            for (int i = 0; i < n; i++)
            {
                if (st.size() != mid && v[i] < mid)
                    st.insert(v[i]);

                if (st.size() == mid)
                {
                    st.clear();
                    seg++;
                }
            }
            return seg == k;
        };

        int lo = 0,
            hi = n + 1;
        while (hi - lo > 1)
        {
            int mid = lo + (hi - lo) / 2;
            if (check(mid))
                lo = mid;
            else
                hi = mid;
        }
        cout << lo << '\n';
    }
    return 0;
}