#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
char ar[N][N];

bool checkBad(int i, int j, int n, int m, char ch)
{
    if (ch == 'U')
        return i == 0;
    if (ch == 'D')
        return i == n - 1;
    if (ch == 'L')
        return j == 0;
    if (ch == 'R')
        return j == m - 1;
    return false;
}

bool checkBad2(int i, int j, int n, int m, vector<vector<bool>> &bad)
{
    if (ar[i][j] == '?')
        return false;
    bool ans = true;
    if (i > 0 && ar[i][j] == 'U')
        ans &= bad[i - 1][j];
    if (i + 1 < n && ar[i][j] == 'D')
        ans &= bad[i + 1][j];
    if (j > 0 && ar[i][j] == 'L')
        ans &= bad[i][j - 1];
    if (j + 1 < m && ar[i][j] == 'R')
        ans &= bad[i][j + 1];
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> ar[i][j];
        }

        vector<vector<bool>> bad(n, vector<bool>(m, false));
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (ar[i][j] != '?')
                {
                    if (checkBad(i, j, n, m, ar[i][j]))
                    {
                        bad[i][j] = true;
                        q.push({i, j});
                    }
                }
            }
        }
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int x = it.first, y = it.second;

            for (vector<int> dir : vector<vector<int>>{
                     {-1, 0, 'D'}, {1, 0, 'U'}, {0, -1, 'R'}, {0, 1, 'L'}})
            {
                int dx = dir[0], dy = dir[1];
                char dch = dir[2];
                int nx = x + dx, ny = y + dy;

                if (nx >= 0 && ny >= 0 && nx < n && ny < m && !bad[nx][ny] && ar[nx][ny] == dch)
                {
                    bad[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (ar[i][j] == '?')
                {
                    int val = 1;
                    if (i > 0)
                        val &= bad[i - 1][j];
                    if (j > 0)
                        val &= bad[i][j - 1];
                    if (i + 1 < n)
                        val &= bad[i + 1][j];
                    if (j + 1 < m)
                        val &= bad[i][j + 1];
                    ans += (!val);
                }
                else if (!bad[i][j])
                    ans++;
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
