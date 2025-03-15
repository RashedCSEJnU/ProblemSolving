#include <bits/stdc++.h>
using namespace std;
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> ans;
        bool flag = false;
        for (int i = 1; i <= n; i++)
        {
            int nxt = ((l + i - 1) / i) * i;
            if (nxt > r)
                flag = true;
            ans.push_back(nxt);
        }
        if (flag)
        {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for (auto val : ans)
            cout << val << ' ';
        cout << '\n';
    }
    return 0;
}