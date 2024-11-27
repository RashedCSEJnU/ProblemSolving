#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> p(n);
    for (auto &pi : p)
    {
        cin >> pi;
    }
    string s;
    cin >> s;
    vector<int> pref(n + 1);
    for (int i = 0; i < n; ++i)
    {
        pref[i + 1] = max(pref[i], p[i]);
    }
    int bad = 0;

    auto yo = [&](int i, int x)
    {
        if (i == n - 1)
            return;
        if (s[i] == 'L' and s[i + 1] == 'R')
        {
            if (pref[i + 1] > i + 1)
            {
                bad += x;
            }
        }
    };

    for (int i = 0; i + 1 < n; ++i)
        yo(i, 1);

    while (q--)
    {
        int i;
        cin >> i;
        i--;
        yo(i - 1, -1);
        yo(i, -1);
        if (s[i] == 'L')
            s[i] = 'R';
        else
            s[i] = 'L';
        yo(i - 1, 1);
        yo(i, 1);
        if (!bad)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        solve();
    }
}