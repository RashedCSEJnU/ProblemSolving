#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, maxi = 0;
        cin >> n >> m;
        vector<vector<int>> arr(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
                maxi = max(maxi, arr[i][j]);
            }

        vector<bool> vis(maxi + 1, false), nei(maxi + 1, false);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                vis[arr[i][j]] = true;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                int col = arr[i][j];
                if (i + 1 < n && arr[i + 1][j] == col)
                    nei[col] = true;
                if (j + 1 < m && arr[i][j + 1] == col)
                    nei[col] = true;
            }

        int ans = 0, ex = 0;
        for (int c = 1; c <= maxi; c++)
        {
            if (vis[c])
            {
                int cost = nei[c] ? 2 : 1;
                ans += cost;
                ex = max(ex, cost);
            }
        }
        ans -= ex;
        cout << ans << "\n";
    }
    return 0;
}