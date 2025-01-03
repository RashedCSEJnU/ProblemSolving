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
        int n, i;
        cin >> n;

        vector<int> v(n), ans(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];

        set<int> st, zero;
        for (int i = 0; i < n; i++)
        {
            if (st.find(v[i]) == st.end())
            {
                ans[i] = v[i];
                st.insert(v[i]);
            }
            else
                zero.insert(i);
        }

        for (int i = 1; i <= n + 10 && !zero.empty(); i++)
        {
            if (st.find(i) == st.end())
            {
                int ind = *zero.begin();
                zero.erase(zero.begin());
                ans[ind] = i;
            }
        }

        for (auto val : ans)
            cout << val << ' ';
        cout << '\n';
    }
    return 0;
}
