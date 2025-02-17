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
        int n, m, k;
        cin >> n >> m >> k;
        if (k < abs(n - m))
        {
            cout << -1 << '\n';
            continue;
        }
        if (n > m) // zero basi
        {
            string s(k, '0');
            n -= k;
            while (n > 0 && m > 0)
            {
                s += "10";
                n--, m--;
            }
            while (m > 0)
            {
                s += '1';
                m--;
            }
            while (n > 0)
            {
                s += '0';
                n--;
            }
            cout << s << '\n';
        }
        else // one basi
        {
            string s(k, '1');
            m -= k;
            while (n > 0 && m > 0)
            {
                s += "01";
                n--, m--;
            }
            while (n > 0)
            {
                s += '0';
                n--;
            }
            while (m > 0)
            {
                s += '1';
                m--;
            }
            cout << s << '\n';
        }
    }
    return 0;
}