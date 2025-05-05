#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

int32_t main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;
        vector<int> a, b;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'A')
                a.push_back(i + 1);
            else
                b.push_back(i + 1);
        }
        sort(all(a)), sort(all(b));
        if (a[0] == 1 && a.back() == n)
        {
            cout << "Alice\n";
            continue;
        }
        if (b[0] == 1 && b.back() == n)
        {
            cout << "Bob\n";
            continue;
        }
        if (a.size() == 1 && b.size() > 1)
        {
            cout << "Bob\n";
            continue;
        }
        if (b.size() == 1 && a.size() > 1)
        {
            cout << "Alice\n";
            continue;
        }
        if (a.size() == 1 && b.size() == 1)
        {
            if (a[0] == 1)
                cout << "Alice\n";
            else
                cout << "Bob\n";
            continue;
        }
        if (a.back() < b[0])
        {
            cout << "Bob\n";
            continue;
        }
        if (b.back() < a[0])
        {
            cout << "Alice\n";
            continue;
        }
        if (a[0] == 1)
        {
            if (a.back() < b.back())
                cout << "Bob\n";
            else
                cout << "Alice\n";
        }
        else
            cout << "Bob\n";
    }
    return 0;
}