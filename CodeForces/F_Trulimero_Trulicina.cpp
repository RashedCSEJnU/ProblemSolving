#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, m, k, cnt = 1;
        cin >> n >> m >> k;

        vector<vector<int>> arr(n + 1, vector<int>(m, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (arr[i - 1][j] == cnt)
                {
                    cnt++;
                    if (cnt > k)
                        cnt = 1;
                }
                cout << cnt << ' ';
                arr[i][j] = cnt++;
                if (cnt > k)
                    cnt = 1;
            }
            cout << '\n';
        }
        cout << '\n';
        

    }
    return 0;
}