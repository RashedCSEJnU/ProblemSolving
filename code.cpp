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
        vector<int> a(n), b(n);
        vector<pair<int, int>> v(n);
        for (int &i : a)
            cin >> i;
        for (int &i : b)
            cin >> i;

        multiset<pair<int, int>> ms;
        for (int i = 0; i < n; i++)
            ms.insert({a[i], b[i]});

        int sum = LONG_LONG_MIN;
        pair<int, int> p;
        for (auto it : ms)
        {
            int tempSum = it.first + it.second;
            if (tempSum > sum)
            {
                sum = tempSum;
                p = it;
            }
        }
        ms.erase(p);

        int ans1 = 0, ans2 = 0, ans3 = 0, MiddleSum = p.first + p.second;
        for (auto it : ms)
        {
            ans2 += it.first;
            ans3 += it.second;
            if (it.first > it.second)
                ans1 += it.first;
            else
                ans1 += it.second;
        }
        int ans = max({ans1 + MiddleSum, ans2 + MiddleSum, ans3 + MiddleSum});
        cout << ans << '\n';
    }
    return 0;
}