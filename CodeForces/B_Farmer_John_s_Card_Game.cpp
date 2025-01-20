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
        vector<pair<vector<int>, int>> ar;
        for (int i = 0; i < n; i++)
        {
            vector<int> temp(m);
            for (int j = 0; j < m; j++)
                cin >> temp[j];

            sort(all(temp));
            ar.push_back({temp, i});
        }
        sort(all(ar));

        // // output ar array
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < m; j++)
        //     {
        //         cout << ar[i].first[j] << " ";
        //     }
        //     cout << endl;
        // }

        bool flag = 1;
        int prev = -1;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (ar[j].first[i] < prev)
                {
                    flag = 0;
                    break;
                }
                prev = ar[j].first[i];
            }
            if (!flag)
                break;
        }
        if (!flag)
            cout << -1 << '\n';
        else
        {
            for (int i = 0; i < n; i++)
                cout << ar[i].second + 1 << ' ';
            cout << '\n';
        }
    }
    return 0;
}