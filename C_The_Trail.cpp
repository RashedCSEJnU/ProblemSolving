#include <bits/stdc++.h>
using namespace std;
#define int long long

void operation(pair<int, int> &start, vector<int> &rowSum, vector<int> &colSum, vector<int> &row, vector<int> &col, vector<vector<int>> &v)
{
    int i = start.first, j = start.second;
    if (row[i] == 1)
    {
        v[i][j] = -rowSum[i];
        row[i]--, col[j]--;
        rowSum[i] += v[i][j];
        colSum[j] += v[i][j];
    }
    else
    {
        v[i][j] = -colSum[j];
        row[i]--, col[j]--;
        rowSum[i] += v[i][j];
        colSum[j] += v[i][j];
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, m;
        string s;
        cin >> n >> m >> s;

        vector<vector<int>> v(n, vector<int>(m));
        vector<int> rowSum(n), colSum(m), row(n), col(m);
        pair<int, int> start = {0, 0};
        row[0] = col[0] = 1;

        for (int i = 0; i < s.length(); i++)
        {
            (s[i] == 'D') ? start.first++ : start.second++;
            row[start.first]++, col[start.second]++;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> v[i][j];
                rowSum[i] += v[i][j];
                colSum[j] += v[i][j];
            }
        }
        start = {0, 0};
        for (int l = 0; l < s.length(); l++)
        {
            if (l == 0)
                operation(start, rowSum, colSum, row, col, v);

            (s[l] == 'D') ? start.first++ : start.second++;
            operation(start, rowSum, colSum, row, col, v);
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cout << v[i][j] << " ";
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}