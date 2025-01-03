#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, m, q;
        cin >> n >> m >> q;
        vector<int> a(m), b(q);
        for (auto &i : a)
            cin >> i;
        for (auto &i : b)
            cin >> i;

        set<int> missing;
        for (int i = 1; i <= n; i++)
            missing.insert(i);

        for (int i : b)
            missing.erase(i);

        for (int i : a)
        {
            if (missing.empty() || (missing.find(i) != missing.end() && missing.size() <= 1))
                cout << 1;
            else
                cout << 0;
        }
        cout << '\n';
    }
    return 0;
}