#include <bits/stdc++.h>
using namespace std;
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &i : a)
            cin >> i;
        set<int> one, two, zero;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 0)
                zero.insert(i);
            else if (a[i] == 1)
                one.insert(i);
            else
                two.insert(i);
        }
        vector<pair<int, int>> ans;
        while (1)
        {
            bool flag = 1;
            if (!one.empty() && !zero.empty() && *zero.rbegin() > *one.begin())
            {
                flag = 0;

                int x = *zero.rbegin(), y = *one.begin();
                ans.push_back({x, y});

                a[x] = 1, a[y] = 0;
                zero.insert(y), zero.erase(x);
                one.insert(x), one.erase(y);
            }
            if (!two.empty() && !one.empty() && *one.rbegin() > *two.begin())
            {
                flag = 0;
                int x = *one.rbegin(), y = *two.begin();
                ans.push_back({x, y});

                a[x] = 2, a[y] = 1;
                one.insert(y), one.erase(x);
                two.insert(x), two.erase(y);
            }
            if (flag)
                break;
        }
        cout << ans.size() << '\n';
        for (auto &i : ans)
            cout << i.first + 1 << ' ' << i.second + 1 << '\n';
    }
    return 0;
}