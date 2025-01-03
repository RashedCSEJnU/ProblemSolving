#include <bits/stdc++.h>
using namespace std;
#define int long long
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        if (k == 1)
        {
            for (int i = 1; i <= n; i++)
                cout << i << ' ';
            cout << endl;
            continue;
        }
        vector<int> v(n);
        int cnt = 1;
        for (int i = k - 1; i < n; i += k)
            v[i] = cnt++;
        for (int i = 0; i < n; i++)
        {
            if (v[i] == 0)
                v[i] = cnt++;
        }
        for (auto val : v)
            cout << val << ' ';
        cout << '\n';
    }
    return 0;
}