#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, m, ans = 0, cnt = 0;
    cin >> n >> m;

    int arr[n + 1][m + 1];
    std::vector<int> row(n + 1), col(m + 1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            cin >> arr[i][j];
            cnt += arr[i][j];
            row[i] += arr[i][j];
            col[j] += arr[i][j];
        }
    }

    while (cnt > 0)
    {
        int i = 0, j = 0;

        while (i < n && j < m)
        {
            if (i == n - 1 && j == m - 1)
                break;
            if (arr[i][j])
            {
                cnt--;
                arr[i][j] = 0;
                row[i]--;
                col[j]--;
            }

            if (row[i] > 0)
                i++;
            else
                j++;
        }
        ans++;
    }

    cout<<ans<<'\n';
    return 0;
}
