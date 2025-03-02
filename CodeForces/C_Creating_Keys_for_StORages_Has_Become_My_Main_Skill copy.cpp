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
        int n, x;
        cin >> n >> x;
        int orValue = 0;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            if ((x | i) <= x)
            {
                v.push_back(i);
                orValue |= i;
            }
            else
                v.push_back(x);
        }
        if (orValue != x)
        {
            v.pop_back();
            v.push_back(x);
        }
        for (auto val : v)
            cout << val << ' ';
        cout << '\n';
    }
    return 0;
}