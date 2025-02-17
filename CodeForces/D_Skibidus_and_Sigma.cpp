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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> a[i][j];

            int sum = accumulate(all(a[i]), 0);
            v.push_back({sum, i});
        }
        sort(rall(v));

        int sum = 0, cnt = n * m;
        for (int i = 0; i < n; i++)
        {
            int ind = v[i].second;
            for (int j = 0; j < m; j++)
            {
                sum += (a[ind][j] * cnt--);
            }
        }
        cout << sum << '\n';
    }
    return 0;
}