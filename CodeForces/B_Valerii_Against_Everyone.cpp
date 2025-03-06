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
        int n, flag = 0;
        cin >> n;

        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            mp[x]++;
            flag |= (mp[x] > 1);
        }
        cout << (flag ? "YES\n" : "NO\n");
    }
    return 0;
}