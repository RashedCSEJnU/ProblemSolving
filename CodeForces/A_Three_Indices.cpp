#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int &i : v)
            cin >> i;

        bool flag = true;
        set<pair<int, int>> prev;
        prev.insert({v[0], 1});
        for (int i = 1; i < n - 1; i++)
        {
            auto it = prev.begin();
            for (int j = i + 1; j < n; j++)
            {
                if (it->first < v[i] && v[i] > v[j])
                {
                    flag = false;
                    cout << "YES\n";
                    cout << it->second << ' ' << i + 1 << ' ' << j + 1 << '\n';
                    break;
                }
            }
            prev.insert({v[i], i + 1});
            if (!flag)
                break;
        }
        if (flag)
            cout << "NO\n";
    }
    return 0;
}