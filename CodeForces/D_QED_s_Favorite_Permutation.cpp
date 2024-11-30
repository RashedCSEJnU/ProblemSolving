#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;

        vector<int> v(n + 1), preMax(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> v[i];
            preMax[i] = max(v[i], preMax[i - 1]);
        }

        string s;
        cin >> s;
        s = '#' + s;

        int badBlock = 0;
        auto func = [&](int i, int x)
        {
            if (i < n && s[i] == 'L' && s[i + 1] == 'R' && preMax[i] > i)
                badBlock += x;
        };

        for (int i = 1; i <= n; i++)
        {
            if (preMax[i] > i)
                func(i, 1);
        }

        while (q--)
        {
            int i;
            cin >> i;

            func(i, -1), func(i - 1, -1); // remove
            s[i] = (s[i] == 'R' ? 'L' : 'R');
            func(i, 1), func(i - 1, 1); // add

            cout << (!badBlock ? "YES\n" : "NO\n");
        }
    }
    return 0;
}