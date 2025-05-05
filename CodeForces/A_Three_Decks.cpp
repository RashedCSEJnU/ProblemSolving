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
        int a, b, c;
        cin >> a >> b >> c;
        int total = (a + b + c);
        int div = total / 3;
        int remain = total % 3;
        if (remain != 0)
        {
            cout << "NO\n";
            continue;
        }

        int rem = c - div;
        int forA = max(1LL, div - a);
        rem -= forA;
        a += forA;
        int forB = max(0LL, div - b);
        rem -= forB;
        b += forB;
        c = div;

        if (rem > 0)
        {
            cout << "NO\n";
            continue;
        }
        if (a == b && b == c)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}