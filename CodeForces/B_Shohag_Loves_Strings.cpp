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
        string s;
        cin >> s;
        int n = s.size();
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            if (i + 1 < n && s[i] == s[i + 1])
            {
                cout << s[i] << s[i + 1] << '\n';
                flag = false;
                break;
            }
            if (i + 2 < n && s[i] != s[i + 1] && s[i + 1] != s[i + 2] && s[i] != s[i + 2])
            {
                cout << s[i] << s[i + 1] << s[i + 2] << '\n';
                flag = false;
                break;
            }
        }

        if (flag)
            cout << -1 << '\n';
    }
    return 0;
}