#include <bits/stdc++.h>
using namespace std;
#define int long long
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
int32_t main()
{
<<<<<<< HEAD
    ios_base::sync_with_stdio(0), cin.tie(0);
=======
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
>>>>>>> 2ea9563d99d69e62673de0f8a51a798d01ebaed0
    int t = 1;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;

        for (int i = min(a, b);; i++)
        {
            if (i % a == i % b)
            {
                cout << i << '\n';
                break;
            }
        }
    }
}