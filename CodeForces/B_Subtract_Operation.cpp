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
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for (auto &i : v)
            cin >> i;
        sort(v.begin(), v.end());
        bool flag = 0;
        for (int i = 0; i < n; i++)
        {
            int val = v[i] + k;
            flag |= binary_search(v.begin(), v.end(), val);
        }
        cout << (flag ? "YES\n" : "NO\n");
    }
    return 0;
}